message ("-- Cleaning up build artifacts for PokemonCatalogue...")

file(REMOVE_RECURSE
  "CMakeFiles/PokemonCatalogue.dir/Catalogue.cpp.o"
  "CMakeFiles/PokemonCatalogue.dir/Catalogue.cpp.o.d"
  "CMakeFiles/PokemonCatalogue.dir/Pokemon.cpp.o"
  "CMakeFiles/PokemonCatalogue.dir/Pokemon.cpp.o.d"
  "CMakeFiles/PokemonCatalogue.dir/PokemonCatalogue.cpp.o"
  "CMakeFiles/PokemonCatalogue.dir/PokemonCatalogue.cpp.o.d"
  "PokemonCatalogue"
  "PokemonCatalogue.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/PokemonCatalogue.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
