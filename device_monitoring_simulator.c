#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef union {
    float temperature;   // Celsius
    int pressure;        // hPa
    float voltage;       // Volts
} Reading;

typedef struct {
    char name[30];
    int type;            // 1=Temperature, 2=Pressure, 3=Voltage
    Reading reading;
} Device;

// Callback functions
void temperature_monitor(Device *device) {
    printf("Temp Sensor [%s]: %.2f°C ", device->name, device->reading.temperature);
    if (device->reading.temperature > 40) {
        printf("HIGH TEMP\n");
    } else if (device->reading.temperature < 0) {
        printf("LOW TEMP\n");
    } else {
        printf("Normal\n");
    }
}

void pressure_monitor(Device *device) {
    printf("Pressure Sensor [%s]: %d hPa ", device->name, device->reading.pressure);
    if (device->reading.pressure > 1050) {
        printf("HIGH PRESSURE\n");
    } else if (device->reading.pressure < 950) {
        printf("LOW PRESSURE\n");
    } else {
        printf("Normal\n");
    }
}

void voltage_monitor(Device *device) {
    printf("Power Sensor [%s]: %.2fV ", device->name, device->reading.voltage);
    if (device->reading.voltage < 2.0) {
        printf("LOW BATTERY\n");
    } else if (device->reading.voltage > 5.0) {
        printf("OVERVOLTAGE\n");
    } else {
        printf("Normal\n");
    }
}

// Custom callback: Alert system
void alert_system(Device *device) {
    if (device->type == 1 && (device->reading.temperature > 50 || device->reading.temperature < -10)) {
        printf("CRITICAL ALERT: %s temperature critical!\n", device->name);
    } else if (device->type == 2 && (device->reading.pressure > 1100 || device->reading.pressure < 900)) {
        printf("CRITICAL ALERT: %s pressure critical!\n", device->name);
    } else if (device->type == 3 && device->reading.voltage < 1.5) {
        printf("CRITICAL ALERT: %s power critical!\n", device->name);
    }
}

// Process device with callback
void process_device(Device *device, void (*callback)(Device*)) {
    callback(device);
}

void show_menu() {
    printf("\n=== Device Monitoring System ===\n");
    printf("1. Display All Readings\n");
    printf("2. Add Random Reading\n");
    printf("3. Run Temperature Monitor\n");
    printf("4. Run Pressure Monitor\n");
    printf("5. Run Voltage Monitor\n");
    printf("6. Alert System\n");
    printf("7. Exit\n");
    printf("Choose: ");
}

int main() {
    srand(time(NULL));
    
    Device *devices = malloc(10 * sizeof(Device));
    int device_count = 10;
    
    // Initialize devices with random readings
    const char *names[] = {"Room1", "Room2", "Room3", "Room4", "Room5",
                          "Storage1", "Storage2", "Lab1", "Lab2", "Control"};
    
    for (int i = 0; i < device_count; i++) {
        strcpy(devices[i].name, names[i]);
        devices[i].type = (i % 3) + 1;
        
        if (devices[i].type == 1)
            devices[i].reading.temperature = 15 + (rand() % 30);
        else if (devices[i].type == 2)
            devices[i].reading.pressure = 950 + (rand() % 100);
        else
            devices[i].reading.voltage = 3.0 + (rand() % 20) / 10.0;
    }
    
    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n=== Device Readings ===\n");
                for (int i = 0; i < device_count; i++) {
                    Device d = devices[i];
                    if (d.type == 1)
                        printf("%2d. %s: %.2f°C\n", i+1, d.name, d.reading.temperature);
                    else if (d.type == 2)
                        printf("%2d. %s: %d hPa\n", i+1, d.name, d.reading.pressure);
                    else
                        printf("%2d. %s: %.2fV\n", i+1, d.name, d.reading.voltage);
                }
                printf("\n");
                break;
                
            case 2: {
                int idx = rand() % device_count;
                if (devices[idx].type == 1)
                    devices[idx].reading.temperature = 15 + (rand() % 30);
                else if (devices[idx].type == 2)
                    devices[idx].reading.pressure = 950 + (rand() % 100);
                else
                    devices[idx].reading.voltage = 3.0 + (rand() % 20) / 10.0;
                printf("Updated %s\n\n", devices[idx].name);
                break;
            }
            
            case 3:
                printf("\n=== Temperature Monitor ===\n");
                for (int i = 0; i < device_count; i++)
                    if (devices[i].type == 1)
                        process_device(&devices[i], temperature_monitor);
                printf("\n");
                break;
                
            case 4:
                printf("\n=== Pressure Monitor ===\n");
                for (int i = 0; i < device_count; i++)
                    if (devices[i].type == 2)
                        process_device(&devices[i], pressure_monitor);
                printf("\n");
                break;
                
            case 5:
                printf("\n=== Voltage Monitor ===\n");
                for (int i = 0; i < device_count; i++)
                    if (devices[i].type == 3)
                        process_device(&devices[i], voltage_monitor);
                printf("\n");
                break;
                
            case 6:
                printf("\n=== Alert System ===\n");
                printf("Devices stored at address: %p\n", (void*)devices);
                for (int i = 0; i < device_count; i++)
                    process_device(&devices[i], alert_system);
                printf("\n");
                break;
                
            case 7:
                free(devices);
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


