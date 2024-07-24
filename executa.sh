#!/bin/bash

# Diretório contendo os arquivos de entrada
input_dir="./instancias-num"

# Programa que será executado
programa="./insertionSort"

# Nome do arquivo de saída
output_file="benchmarkInsertionSort.txt"

# Limpa o arquivo de saída se já existir
> "$output_file"

# Verifica se o diretório de entrada existe
if [ ! -d "$input_dir" ]; then
    echo "Diretório $input_dir não encontrado!"
    exit 1
fi

# echo "Debug"

# Loop através dos arquivos no diretório
for instancia in "$input_dir"/*; do
    if [ -f "$instancia" ]; then
        echo "Executando o programa com a instancia: $instancia"
        echo "---------------------------------"
        
        # Executa o programa com o arquivo como parâmetro e redireciona a saída para o arquivo
        "$programa" "$instancia" >> "$output_file" 2>&1
    fi
done

echo "Saída dos programas foi armazenada em $output_file"