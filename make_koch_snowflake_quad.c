/*****************************************************************************/
/*                                                                           */
/*                       2015-2020      Martin Held                          */
/*                                                                           */
/*                                                                           */
/* E-Mail:      held@cs.sbg.ac.at                                            */
/* Snail Mail:  Universitaet Salzburg, FB Computerwissenschaften,            */
/*              Jakob-Haringer Str. 2, A-5020 Salzburg, Austria (Europe).    */
/*                                                                           */
/*****************************************************************************/

/* get standard i/o library */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifdef BOOL_DEFINED
typedef bool boolean;
#else
#define false 0
#define true  (!false)
typedef unsigned char  boolean;
#endif

#define Pi2 6.2831853071795865


#define UniformRandom(C) ((C) = (double) (lrand48() % (1000000)) / 1000000)



void drawCurve(FILE *output,   
               double x1, double y1,           /* Startpunkt der Teilstrecke */
               double x2, double y2,           /* Endpunkt der Teilstrecke   */
               boolean perturb,                /* Punkte perturbieren?       */
               int level)                      /* Schachtelungstiefe         */
{
   /*                                                                        */
   /* Jede Teilstrecke wird eindeutig durch Start- und Endpunkt definiert.   */
   /* Anzahl der Teilstrecken = 4*8^(level-1),                               */
   /* level 1 = quadrat.                                                     */
   /*                                                                        */
   double x3, y3, x4, y4, vx, vy, sidelength, angle;
   
   if (level > 1) {
      /* Teilstrecke in acht neue Teilstrecken mit ein Viertel der           */
      /*  urspruenglichen Laenge zerlegen                                    */
      level -= 1;
      vx = x2 - x1;
      vy = y2 - y1;
      vx /= 4.0;
      vy /= 4.0;
      if (perturb) {
         sidelength = sqrt(vx * vx + vy * vy) / (level * 6.0);
      }
      
      /* erste Teilstrecke                                                   */
      x4 = x3 = x1 + vx;
      y4 = y3 = y1 + vy;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);

      /* zweite Teilstrecke                                                  */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 - vy;
      y4 = y3 = y3 + vx;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);

      /* dritte Teilstrecke                                                  */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 + vx;
      y4 = y3 = y3 + vy;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);
      
      /* vierte Teilstrecke                                                  */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 + vy;
      y4 = y3 = y3 - vx;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);

      /* fuenfte Teilstrecke                                                 */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 + vy;
      y4 = y3 = y3 - vx;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);

      /* sechste Teilstrecke                                                 */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 + vx;
      y4 = y3 = y3 + vy;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);
      
      /* siebte Teilstrecke                                                  */
      x1 = x4;
      y1 = y4;
      x4 = x3 = x3 - vy;
      y4 = y3 = y3 + vx;
      if (perturb) {
         UniformRandom(angle);
         x4 += sin(angle * Pi2) * sidelength;
         y4 += cos(angle * Pi2) * sidelength;
      }
      drawCurve(output, x1, y1, x4, y4, perturb, level);

      /* achte Teilstrecke                                                   */
      drawCurve(output, x4, y4, x2, y2, perturb, level);
   }
   else {
      /* Teilstrecke ausgeben                                               */
      if (perturb)  fprintf(output, "%f %f\n", x2, y2);
      else          fprintf(output, "%d %d\n", (int) x2, (int) y2);
   }
    
   return;
}


void PrintHeader(void)
{
   printf("\n");
   printf("***********************************************************\n");
   printf("*                                                         *\n");
   printf("*               make_koch_snowflake_quad                  *\n");
   printf("*                                                         *\n");
   printf("* Generation of a (rectilinear) Koch snowflake.           *\n");
   printf("*                                                         *\n");
   printf("*      Martin Held 2015-2020        held@cs.sbg.ac.at     *\n");
   printf("*                                                         *\n");
   printf("***********************************************************\n");

   return;
}


void OpenFile(FILE  **output, const char *file_name)
{
   /* open file */
   if((*output = fopen(file_name, "w")) == NULL) {
      fprintf(stderr,"*** Output file not created! ***\n");
      exit(1);
   }
   
   return;
}   


int main(int argc, char **argv)
{
   int count = 1;
   boolean success = true;
   boolean name_read = false;
   int level = 0;
   FILE *output;
   char *file_name = "koch.line";
   int i, number;
   boolean perturb = false;
   int seed = 0;
   double max;

   PrintHeader();

   /*                                                                        */
   /* parse command-line arguments                                           */
   /*                                                                        */
   while ((count < argc)  &&  success)    {

      if (strcmp(argv[count],"--number") == 0) {
         ++count;
         if ((success = (count < argc)))  level = atoi(argv[count]);
      }
      else if (strcmp(argv[count],"--perturb") == 0) {
         perturb = true;
      }
      else if (strcmp(argv[count],"--seed") == 0) {
         ++count;
         if ((success = (count < argc)))  seed = atof(argv[count]);
      }
      else if (strcmp(argv[count],"--output") == 0) {
         ++count;
         if ((success = (count < argc))) {
            file_name = argv[count];
            name_read = true;
         }
      }
      else {
         success = false;
      }
      ++count;
   }

   if (!success  ||  !name_read  ||  (level <= 0)) {
      if (!success) 
         printf("\nUnrecognized command-line option: %s\n", argv[count-1]); 
      printf("\nUsage: make_koch_snowflake_quad --number N --output XYZ\n                                    [--perturb] [--seed S] \n       where N is a positive integer,\n             S is a non-negative integer.\n"); 
      exit(2);
   }

   /*                                                                        */
   /* initialization                                                         */
   /*                                                                        */
   srand48(seed);
   OpenFile(&output, file_name);
   number = 4;
   for (i = 1; i < level; i++) {
      number *= 8;
   }
   fprintf(output, "%d\n", number + 1);
   printf("... generating %d vertices: ", number);
   fflush(stdout);

   /*                                                                        */
   /* recursive generation of Koch curve                                     */
   /*                                                                        */
   if (perturb) {
      fprintf(output, "0.0 0.0\n");
      drawCurve(output, 0.0, 0.0, 1.0, 0.0, perturb, level);
      drawCurve(output, 1.0, 0.0, 1.0, 1.0, perturb, level);
      drawCurve(output, 1.0, 1.0, 0.0, 1.0, perturb, level);
      drawCurve(output, 0.0, 1.0, 0.0, 0.0, perturb, level);
   }
   else {
      max = 1;
      for (i = 1; i < level; i++) {
         max *= 4;
      }
      fprintf(output, "0 0\n");
      drawCurve(output, 0.0, 0.0, max, 0.0, perturb, level);
      drawCurve(output, max, 0.0, max, max, perturb, level);
      drawCurve(output, max, max, 0.0, max, perturb, level);
      drawCurve(output, 0.0, max, 0.0, 0.0, perturb, level);
   }

   fclose(output);

   printf("done\n");

   return 0;
}
