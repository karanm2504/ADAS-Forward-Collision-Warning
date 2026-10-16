
#include <stdio.h>


typedef enum
{
    SAFE,
    WARNING,
    CRITICAL
} WarningLevel;

// Calculate Time-to-Collision (TTC)
float calculateTTC(float ego_speed,
                   float lead_speed,
                   float distance)
{
    // Step 1: Validate inputs
    if (ego_speed < 0.0f ||
        lead_speed < 0.0f ||
        distance < 0.0f)
    {
        return -2.0f;  // Invalid input
    }

    // Step 2: Calculate closing speed
    float closing_speed = ego_speed - lead_speed;

    // Step 3: Check whether vehicles are approaching
    if (closing_speed <= 0.0f)
    {
        return -1.0f;  // No collision predicted
    }

    // Step 4: Convert speed from km/h to m/s
    float closing_speed_ms = closing_speed / 3.6f;

    // Step 5: Calculate TTC
    float ttc = distance / closing_speed_ms;

    return ttc;
}

// Classify collision warning level

int getWarningLevel(float ttc)
{
    if (ttc > 3.0f)
    {
        return 0;  // SAFE
    }
    else if (ttc > 1.5f)
    {
        return 1;  // WARNING
    }
    else
    {
        return 2;  // CRITICAL
    }
}

int main(void)
{
    // Simulation inputs
    float ego_speed = 90.0f;
    float lead_speed = 54.0f;
    float distance;

    printf("Enter distance in metres: ");

    if (scanf("%f", &distance) != 1)
    {
    printf("Error: Invalid distance input\n");
    return 1;
    }

    // Calculate TTC
    float ttc = calculateTTC(ego_speed, lead_speed, distance);

    // Handle result
    if (ttc == -2.0f)
{
    printf("Error: Invalid input\n");
}
else if (ttc == -1.0f)
{
    printf("Vehicles are not approaching\n");
}
else
{
    printf("TTC = %.2f seconds\n", ttc);

    int warning_level = getWarningLevel(ttc);

   if (warning_level == SAFE)
    {
    printf("Status: SAFE\n");
    }
    else if (warning_level == WARNING)
    {
    printf("Status: WARNING\n");
    }
    else
    {
    printf("Status: CRITICAL\n");
    }
}

    return 0;
}
