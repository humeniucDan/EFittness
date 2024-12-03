//
// Created by koath on 12/3/2024.
//

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "argonhelper.h"

#define ARGON2_HASH_LEN 32
#define ARGON2_SALT_LEN 9

char valToHexChar(char& val){
    if( 0 <= val && val < 10) return val + '0';
    if(10 <= val && val < 16) return val + 'a';
    return 0;
}

std::string byteToHexStr(char& bin){
    char
        littleEndian = (0b00001111 & bin),
        bigEndian = (0b11110000 & bin)
    ;

    return std::string{valToHexChar(bigEndian)} + std::string{valToHexChar(littleEndian)};
}

std::string hashToHex(const char* hash, size_t length) {
    std::ostringstream oss;
    for (size_t i = 0; i < length; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (static_cast<unsigned char>(hash[i]) & 0xFF);
    }
    return oss.str();
}

std::string hashPassword(const std::string &password) {
    char hash[ARGON2_HASH_LEN];
    memset(hash, 0, ARGON2_SALT_LEN);
    char salt[ARGON2_SALT_LEN] = "somesalt"; // Use a proper random salt in production
    memset(salt, 0, ARGON2_SALT_LEN);

    if (argon2i_hash_raw(2, 1 << 16, 1, password.c_str(), password.length(), salt, ARGON2_SALT_LEN, hash, ARGON2_HASH_LEN) != ARGON2_OK) {
        throw std::runtime_error("Error hashing password");
    }

    std::string hashStrnig = hashToHex(hash, ARGON2_HASH_LEN);

    return hashStrnig;
}