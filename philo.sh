#!/bin/bash

# Archivo para guardar sin colores
OUTPUT_FILE="philo_output_clean.txt"

# ANSI regex para quitar colores
ansi_clean() {
    sed -r "s/\x1B\[[0-9;]*[mK]//g"
}

# Ejecutar philo, ver con colores, pero guardar sin colores
./philo 4 410 200 200 50 | tee >(ansi_clean > "$OUTPUT_FILE")

# Esperar a que termine
wait $!

echo ""
echo "📊 Analizando salida limpia..."

# Inicializar contador de comidas
declare -A eat_count
for i in {1..4}; do
    eat_count[$i]=0
done

# Revisar línea por línea
last_time=0
line_number=0
success=true

while read -r line; do
    ((line_number++))
    
    if [[ "$line" =~ ^([0-9]+)[[:space:]]+([1-4])[[:space:]]+is\ eating ]]; then
        ts=${BASH_REMATCH[1]}
        id=${BASH_REMATCH[2]}
        ((eat_count[$id]++))
    fi

    if [[ "$line" =~ ^([0-9]+)[[:space:]] ]]; then
        current_time=${BASH_REMATCH[1]}
        if [ "$current_time" -lt "$last_time" ]; then
            echo "❌ Error de tiempo en línea $line_number: $current_time < $last_time"
            success=false
        fi
        last_time=$current_time
    fi
done < "$OUTPUT_FILE"

# Mostrar resumen
echo ""
echo "🍝 Conteo de comidas por filósofo:"
for i in {1..4}; do
    count=${eat_count[$i]}
    echo "Filósofo $i comió $count veces"
    if [ "$count" -ne 50 ]; then
        echo "❌ Error: Filósofo $i no comió 50 veces."
        success=false
    fi
done

# Resultado final
if [ "$success" = true ]; then
    echo "✅ Todo correcto: tiempos OK y cada filósofo comió 50 veces."
    exit 0
else
    echo "⚠️ Hubo problemas. Revisa los errores arriba."
    exit 1
fi
