#include <REG51.H>

// Define pin connections for traffic lights
sbit RED = P1^0;
sbit YELLOW = P1^1;
sbit GREEN = P1^2;

// Function prototypes
void delay_ms(unsigned int ms);
void initialize();

int main() {
    initialize();
    
    while(1) {
        // Green light for 5 seconds
        GREEN = 0;
        YELLOW = 0;
        RED = 1;
        delay_ms(5000);
        
        // Yellow light for 2 seconds
        GREEN = 0;
        YELLOW = 1;
        RED = 0;
        delay_ms(2000);
        
        // Red light for 5 seconds
        GREEN = 1;
        YELLOW = 0;
        RED = 0;
        delay_ms(5000);
    }
}

void initialize() {
    // Initialize all lights to off
    RED = 0;
    YELLOW = 0;
    GREEN = 0;
}

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 123; j++); // Adjust this value based on your microcontroller's clock speed
}