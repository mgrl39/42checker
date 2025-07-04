#!/bin/bash
#echo "in maintenance 🔧 mgrl39"

#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No color

# Base URL of the GitHub repository
GITHUB_URL="https://raw.githubusercontent.com/mgrl39/42checker/main/libft"

# Function to download a file from GitHub repository
download_file() {
    local filename=$1
    echo -e "${BLUE}Downloading $filename...${NC}"
    wget -q -O "$filename" "$GITHUB_URL/$filename"
    if [[ ! -f "$filename" ]]; then
        echo -e "${RED}Failed to download $filename.${NC}"
        cleanup
        exit 1
    fi
}

# Cleanup function to remove downloaded files
cleanup() {
    echo -e "${BLUE}Cleaning up...${NC}"
    rm -f list.txt colors.h a.out "${ex_name}"
}

# Set trap to call cleanup on EXIT
trap cleanup EXIT

# Download the list of exercises and colors.h file
download_file "list.txt"
download_file "colors.h"

# Read the list of exercises into an array
mapfile -t exercises < list.txt

# List .c files in the current directory that are in the list of exercises
c_files=$(ls *.c 2>/dev/null)
evaluatable_files=()

# Check .c files that can be evaluated
for exercise in "${exercises[@]}"; do
    file="ft_${exercise}.c"
    if [[ -f "$file" ]]; then
        evaluatable_files+=("$file")
    fi
done

# Display .c files in the current directory that can be evaluated
echo -e "${YELLOW}.c files in the current directory that can be evaluated:${NC}"
for file in "${evaluatable_files[@]}"; do
    echo -e "${GREEN}$file${NC}"
done

# Display known exercise options
echo -e "${YELLOW}Select an exercise to evaluate:${NC}"
select exercise in "${exercises[@]}"; do
    if [[ " ${exercises[@]} " =~ " ${exercise} " ]]; then
        echo -e "${GREEN}You selected: $exercise${NC}"
        break
    else
        echo -e "${RED}Invalid option. Please select a valid exercise.${NC}"
    fi
done

# Download the main corresponding to the exercise
main_url="$GITHUB_URL/ft_${exercise}_main.c"
ex_name="ft_${exercise}_main.c"
download_file "$ex_name"

# Check if the exercise file exists
if [[ ! -f "ft_${exercise}.c" ]]; then
    echo -e "${RED}The file ft_${exercise}.c does not exist in the current directory.${NC}"
    exit 1
fi

# Try to compile with the downloaded file and the selected exercise
echo -e "${BLUE}Compiling: cc -Wall -Wextra -Werror $ex_name ft_${exercise}.c -o a.out${NC}"
cc -Wall -Wextra -Werror "$ex_name" "ft_${exercise}.c" -o a.out

# Check if the compilation was successful
if [[ ! -f "a.out" ]]; then
    echo -e "${RED}Initial compilation error.${NC}"
    echo -e "${BLUE}Trying to compile the library with make...${NC}"
    
    # Try to compile the library using make
    make
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}Makefile compilation failed.${NC}"
        exit 1
    fi

    # Try to compile again using the compiled library
    echo -e "${BLUE}Compiling with the library: cc -Wall -Wextra -Werror $ex_name ft_${exercise}.c libft.a -o a.out${NC}"
    cc -Wall -Wextra -Werror "$ex_name" "ft_${exercise}.c" libft.a -o a.out

    # Check if the compilation was successful
    if [[ ! -f "a.out" ]]; then
        echo -e "${RED}Compilation error even with the library.${NC}"
        exit 1
    fi
fi

# Run the compiled file
echo -e "${BLUE}Running the compiled file:${NC}"
./a.out

# Check the result of the execution
if [[ $? -ne 0 ]]; then
    echo -e "${RED}Execution error of the compiled file.${NC}"
    exit 1
fi

echo -e "${GREEN}Tests completed.${NC}"
