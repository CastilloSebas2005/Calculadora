set(HEADER_LIST
"${Calculadora_SOURCE_DIR}/include/*.hh"
)

add_executable(Calculadora
calculadora.cc
token.cc
tokenizer.cc
shunting_yard.cc
postfija.cc
)

target_include_directories(Calculadora PUBLIC ../include)