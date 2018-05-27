
:: Debug

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\eglib.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libgcmonosgen.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmonoruntime.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmono-static.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmonoutils.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\eglib.pdb" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libgcmonosgen.pdb" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmonoruntime.pdb" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmono-static.pdb" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Debug\libmonoutils.pdb" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"

:: Release

xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Release\eglib.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Release\libgcmonosgen.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Release\libmonoruntime.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Release\libmono-static.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"
xcopy /s /Y "C:\Flax\3rdParty\mono\msvc\build\xbox\sgen\x64\lib\Release\libmonoutils.lib" "C:\Flax\Source\3rdParty\XboxOne\x64\Debug\"

echo "Done!"
