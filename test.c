#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getChoice(void);
int findAtomicNumber(void);
int findAtomicSymbol(void);
int findAtomicElement(void);
int findAtomicMass(void);
char blockType(int);
char propertyType(int);
void displayResult(int, char, char);

char elements[112][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Flourine", "Neon","Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphur", "Chlorine", "Argon","Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc","Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton","Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium","Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
                      "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
                      "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
                      "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",
                      "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium",
                      "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium",
                      "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium"};

char symbols[112][5] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                       "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
                       "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
                       "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",
                       "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
                       "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
                       "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", ",Md", "No", "Lr",
                       "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn"};

double masses[112] = {1.00, 4.00, 6.94, 9.01, 10.81, 12.01, 14.00, 16.00, 20.00, 20.18, 23.00, 24.31, 26.99, 28.08, 30.97, 32.06, 35.45, 39.09, 40.07, 44.95, 47.86, 50.94,
                      51.99, 54.93, 55.84, 58.69, 58.93, 63.54, 65.39, 69.7, 72.64, 74.92, 78.96, 79.90, 83.80, 85.46, 87.62, 88.90, 91.22, 92.90, 95.94, 98.00, 101.07,
                      102.90, 106.42, 107.86, 112.41, 114.81, 118.71, 121.76, 127.6, 126.90, 131.29, 13.90, 137.32, 138.90, 140.11, 140.90, 144.24, 145.00,
                      150.36, 151.96, 157.25, 158.92, 162.50, 164.93, 167.5, 168.93, 173.04, 174.96, 178.49, 180.94, 183.84, 186.20, 190.23, 192.21, 195.07, 196.97,
                      200.59, 204.38, 207.20, 208.98, 209.00, 210.00, 222.00, 223.00, 226.00, 227.00, 231.03, 232.03, 237.00, 238.03, 243, 244, 247, 247, 251, 252, 257, 258,
                      259, 261, 262, 264, 266, 268, 272, 277, 276, 281, 280, 285};

int main(void) {
    int index = 999, choice;
    do {
        choice = getChoice();
        char blockChar, propertyChar;
        switch (choice) {
            case 1:
                index = findAtomicNumber();
                break;
            case 2:
                index = findAtomicSymbol();
                break;
            case 3:
                index = findAtomicElement();
                break;
            case 4:
                index = findAtomicMass();
                break;
            case 5:
                return 0;
            default:
                system("cls");
                printf("\n\n\t\t\t\tSorry Buddy,Your Choice is Wrong. \n");
                printf("\n\t\t\t\tWill you wanna try again? \n\n");
        }
        if (index == -1) {
            system("cls");
            printf("\t\t\t\t\t\tSorry, \n\t\t\t\t\tThat element is not found. \n");
            printf("\t\t\t\t     Please try again. \n\n");
        } else if (index == 999)
            continue;
        else {
            system("cls");
            blockChar = blockType(index);
            propertyChar = propertyType(index);
            displayResult(index, blockChar, propertyChar);
        }
        index = 999;
    } while (choice != 5);
    return 0;
}

int getChoice(void) {
    int choice;
    printf("\n\nEnter the following number that you wanna search:\n\n");
    printf("1. Search by ATOMIC NUMBER\n");
    printf("2. Search by ATOMIC SYMBOL\n");
    printf("3. Search by ATOMIC NAME\n");
    printf("4. Search by ATOMIC MASS\n");
    printf("5. QUIT\n");
    printf("\nEnter Your Choice : ");
    scanf("%d", &choice);
    return choice;
}

int findAtomicNumber(void) {
    int num;
    printf("\nEnter the Atomic Number that you wanna search: ");
    scanf("%d", &num);
    num--;
    if (num >= 0 && num < 112)
        return num;
    else
        return -1;
}

int findAtomicElement(void) {
    char nameInput[20];
    int i, found = 0;
    printf("\nEnter the Atomic Name that you wanna search: ");
    scanf("%s", nameInput);
    for (i = 0; i < 112; i++) {
        if (strcmp(nameInput, elements[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found == 1)
        return i;
    else
        return -1;
}

int findAtomicSymbol(void) {
    char symbolInput[5];
    int i, found = 0;
    printf("\nEnter the Atomic Symbol that you wanna search: ");
    scanf("%s", symbolInput);
    for (i = 0; i < 112; i++) {
        if (strcmp(symbolInput, symbols[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found == 1)
        return i;
    else
        return -1;
}

int findAtomicMass(void) {
    double mass;
    int i, found = 0;
    printf("\nEnter the Atomic Mass that you wanna search: ");
    scanf("%lf", &mass);
    for (i = 0; i < 112; i++) {
        if (masses[i] == mass) {
            found = 1;
            break;
        }
    }
    if (found == 1)
        return i;
    else
        return -1;
}

char blockType(int index) {
    char ch = ' ';
    int num = index + 1;
    /* Code for determining block type */
    return ch;
}

char propertyType(int index) {
    int num = index + 1;
    char ch = ' ';
    /* Code for determining property type */
    return ch;
}

void displayResult(int index, char blockChar, char propertyChar) {
    printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
    printf("\n\t\t\t\t\tAtomic Number     : %d\n", (index + 1));
    printf("\t\t\t\t\tAtomic Symbol     : %s\n", symbols[index]);
    printf("\t\t\t\t\tAtomic Name       : %s\n", elements[index]);
    printf("\t\t\t\t\tAtomic Mass       : %.2f\n", masses[index]);
    printf("\t\t\t\t\tBlock             : %c\n", blockChar);
    printf("\t\t\t\t\tProperty          : ");
    if (propertyChar == 'n')
        printf("Non-Metal\n");
    else if (propertyChar == 's')
        printf("Metalloid\n");
    else
        printf("Metal\n");
    printf("\n\t\t\t\t\t\tThank You ! \n\n\n");
}
