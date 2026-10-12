
#include <stdio.h>

float calculateTTC(float ego_speed,
                   float lead_speed,
                   float distance)
{
    float closing_speed = ego_speed - lead_speed;

    if (closing_speed <= 0.0f)
    {
        return -1.0f;
    }

    float closing_speed_ms = closing_speed / 3.6f;
    float ttc = distance / closing_speed_ms;

    return ttc;
}


void checkWarning(float ttc)
{
    if (ttc > 3.0f)
    {
        printf("Status: SAFE\n");
    }
    else if (ttc > 1.5f)
    {
        printf("Status: WARNING\n");
    }
    else
    {
        printf("Status: CRITICAL\n");
    }
}

int main(void)
{
    float ego_speed = 90.0f;
    float lead_speed = 54.0f;
    float distance = 10.0f;

    float ttc = calculateTTC(ego_speed, lead_speed, distance);

    if (ttc >= 0.0f)
{
    printf("TTC = %.2f seconds\n", ttc);
    checkWarning(ttc);
}
else
{
    printf("Vehicles are not approaching\n");
}

    return 0;
}