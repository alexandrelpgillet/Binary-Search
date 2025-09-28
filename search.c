#include <stdio.h>

int  p = 0;


int  search (int *V, int low, int high, int element,int N){
   
   p+=1;

   int pos =0;
  
   if(low<high){
     
      
      if(V[high]==element) return high;
     
      else if(V[low]==element) return low;
     
      else if(V[high]==V[low]) return  -1;    
     // if(V[high]==V[low] && element == V[low]) return low;
 
      pos = 0 + ((element-V[low])*(high-low))/ (V[high]-V[low]);
      
      
      if(pos>N-1) return -1;
      if(pos<0) return -1;
      if(V[pos]==element){
        
       return pos;
      }
      else {
         
        if(element<V[pos]){
          
          pos = search(V,low,pos,element,N);
        }
        
        if(element>V[pos]){
           
         pos = search(V,pos,high,element,N);
        }
      }
      
     
      
   }
   else {

     return -1;
   }
   
   return  pos;

}


int main(){

    int V[]={1,4,5,6,7,8,9,10,12,13,16};

    for(int i = 0 ; i<1000 ; i++){
      
      V[i]=i;
    }
     
    

    printf("-Posicao do item encontrada:");
    printf("%d", search(V,0, sizeof(V)/4-1,324, sizeof(V)/4-1));   
    printf("\n-Quantidade de chamadas da função search() : %d",p);

}
