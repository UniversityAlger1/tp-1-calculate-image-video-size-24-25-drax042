#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char *unit)
{
   // YOUR CODE HERE - BEGIN
   float resultatOctets = w * h * 3;

   // Vérification de l'unité choisie
   if (unit == NULL)
   {
      return -1; // Retourne une valeur d'erreur pour une unité invalide
   }

   if (strcmp(unit, "o") == 0)
   {
      return resultatOctets; // Octets
   }
   else if (strcmp(unit, "bt") == 0)
   {
      return resultatOctets * 8; // Bits
   }
   else if (strcmp(unit, "ko") == 0)
   {
      return resultatOctets / 1024; // Kilooctets
   }
   else if (strcmp(unit, "mo") == 0)
   {
      return resultatOctets / (1024 * 1024); // Mégaoctets
   }
   else if (strcmp(unit, "go") == 0)
   {
      return resultatOctets / (1024 * 1024 * 1024); // Gigaoctets
   }
   else
   {
      return -1; // Retourne une valeur d'erreur pour une unité non reconnue
   }
   // YOUR CODE HERE - END
   return 0;
}
