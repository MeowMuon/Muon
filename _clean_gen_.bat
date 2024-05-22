del /s /q *.vcxproj
del /s /q *.vcxproj.filters
del /s /q *.vcxproj.user
del /q *.sln

git submodule foreach git reset --hard

call _generate_.bat