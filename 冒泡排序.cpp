 for (int i = 0; i < count ; i++)
 {
     for (int j = 0; j < count  - i; j++)
     {
         if (c[i] > c[i + j])
         {
             int temp = c[i];
             c[i] = c[i + j];
             c[i + j] = temp;
         }
     }
 }