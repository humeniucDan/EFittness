$executables = @(
        "userauth\cmake-build-debug\userauth.exe", 
        "userdata\cmake-build-debug\userdata.exe", 
        "tracker\cmake-build-debug\tracker.exe")

Write-Host "Checking executable paths..."
foreach ($exe in $executables) {
    if (-Not (Test-Path $exe)) {
        Write-Host "Error: $(Split-Path -Leaf $exe) not found at $exe"
        exit 1
    }
}

Write-Host "Starting apps..."
foreach ($exe in $executables) {
    Start-Process -FilePath $exe
}
