:: Testing static linking deploy

::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\libgcmonosgen.*"
::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\libtest.*"
::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\MonoPosixHelper.*"
::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\mono-2.0.*"
::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\mono-2.0-dac.*"
::del /S /Q "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\*.exp"

::xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Lib\Debug\*.lib" "C:\Flax\Source\3rdParty\Windows\x64\Debug\"
::xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Lib\Debug\*.pdb" "C:\Flax\Source\3rdParty\Windows\x64\Debug\"

:: Win64

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Debug\mono-2.0-sgen.lib" "C:\Flax\Source\3rdParty\Windows\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Bin\Debug\mono-2.0-sgen.dll" "C:\Flax\Source\3rdParty\Windows\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Bin\Debug\mono-2.0-sgen.pdb" "C:\Flax\Source\3rdParty\Windows\x64\Debug\"

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\lib\Release\mono-2.0-sgen.lib" "C:\Flax\Source\3rdParty\Windows\x64\Release\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Bin\Release\mono-2.0-sgen.dll" "C:\Flax\Source\3rdParty\Windows\x64\Release\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\x64\Bin\Release\mono-2.0-sgen.pdb" "C:\Flax\Source\3rdParty\Windows\x64\Release\"

:: Win32

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\lib\Debug\mono-2.0-sgen.lib" "C:\Flax\Source\3rdParty\Windows\Win32\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\Bin\Debug\mono-2.0-sgen.dll" "C:\Flax\Source\3rdParty\Windows\Win32\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\Bin\Debug\mono-2.0-sgen.pdb" "C:\Flax\Source\3rdParty\Windows\Win32\Debug\"

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\lib\Release\mono-2.0-sgen.lib" "C:\Flax\Source\3rdParty\Windows\Win32\Release\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\Bin\Release\mono-2.0-sgen.dll" "C:\Flax\Source\3rdParty\Windows\Win32\Release\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\win\sgen\Win32\Bin\Release\mono-2.0-sgen.pdb" "C:\Flax\Source\3rdParty\Windows\Win32\Release\"

echo "Done!"
