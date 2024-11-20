#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
   float resultatOctets = (w * h *  1 * fps) *durationCredits + (w * h * 3 * fps) * (durationMovie); // la section en noir et blanc ne concerne que les credits

   // Vérification de l'unité choisie
   if (unit == NULL)
   {
      return -1; // Retourne une valeur d'erreur pour une unité invalide
   }

   if (strcmp(unit, "o") == 0) // verfier la chaine introduite dans la fonction
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