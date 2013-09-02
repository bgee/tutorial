FILE(REMOVE_RECURSE
  "CMakeFiles/\${file%.*}.a.dir/main.cpp.o"
  "lib\${file%.*}.a.pdb"
  "lib\${file%.*}.a.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/${file%.*}.a.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
