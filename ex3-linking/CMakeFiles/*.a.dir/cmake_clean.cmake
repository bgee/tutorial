FILE(REMOVE_RECURSE
  "CMakeFiles/*.a.dir/main.cpp.o"
  "lib*.a.pdb"
  "lib*.a.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/*.a.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
