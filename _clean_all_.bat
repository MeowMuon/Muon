rd /s /q "_bin\"
rd /s /q "_obj\"
del /s /q imgui.ini

del /s /q *.vcxproj
del /s /q *.vcxproj.filters
del /s /q *.vcxproj.user
del /q *.sln

git submodule foreach git reset --hard
