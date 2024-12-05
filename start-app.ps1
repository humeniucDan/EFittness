# Resolve paths
$userauthPath = "userauth\cmake-build-debug\userauth.exe"
$userdataPath = "userdata\cmake-build-debug\userdata.exe"
# $userdataPath = "(Resolve-Path ".\userdata\cmake-build-debug\userdata.exe").Path"

# Check if files exist
if (-Not (Test-Path $userdataPath)) {
    Write-Host "Error: userdata.exe not found at $userdataPath"
    exit 1
}
if (-Not (Test-Path $userauthPath)) {
    Write-Host "Error: userauth.exe not found at $userauthPath"
    exit 1
}

# Start processes
Start-Process -FilePath $userauthPath
Start-Process -FilePath $userdataPath
