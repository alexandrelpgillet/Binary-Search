#include <stdlib.h>
#include <stdio.h>


//Estrutura do dado User a ser inserido no meu dicionário
typedef struct User{
    
    int id;
    char *name;
    float amount;
}User;


//Estrutura do diconário de dados
typedef struct Dictionary{

    int max_size;
    int size;
    User *V;

}Dictionary;


//Função para criar um dicionário de dados
int createDictionary(Dictionary *T,int max_size){
    
    T->max_size=max_size;
    T->size =0;

    T->V = (User*)malloc(sizeof(User)*max_size);

    if(!T->V){

        exit(-10);
    }
    
    

}

//Função para apagar o dicionário da memória heap
int clearDictionary(Dictionary *T){
    
    
    free(T->V);
    T->size =0;
    T->max_size=0;

    if(T->V){
       
        exit(-11);
    }
}


//Função para inserir um dado no meu dicionário
int insertDictionary(Dictionary *T, User data){
    
    if(T->size>=T->max_size)
    {

        T->V = (User*) realloc(T->V, sizeof(User)*T->max_size);
        T->max_size *=10; 
    
    }

    T->V[T->size]=data;
    T->size+=1;
}


//Função para printar os dados do  dicionário inteiro
void printDictionary(Dictionary *T){

    for(int i =0 ; i<T->size; i++){

        printf("id = %d | name = %s| amount = R$ %0.2f\n", T->V[i].id, T->V[i].name, T->V[i].amount);
    }
}



//Busca binária usando recursão
int searchDictionary(Dictionary *T,int low, int high, User data){
     
    
    
    if(low<=high){

        
        
        int pos = (low+high)/2;
        
        
        if(data.id<T->V[pos].id) pos = searchDictionary(T,low,pos-1, data);

        else if(data.id>T->V[pos].id) pos = searchDictionary(T,pos+1,high, data);

        else if(data.id==T->V[pos].id) return pos;
    
    }
    else
    {
        return -1;
    }
    
    
    

    
}


//Busca binária sem recursão
int searchDictionaryNoRecursion(Dictionary *T, int low , int high, User data){
    
    int pos;
     
    while(low<=high)
    {
        pos = (low+high)/2;

        if(data.id<T->V[pos].id) high = pos-1;

        if(data.id>T->V[pos].id) low = pos+1;

        if(data.id == T->V[pos].id) return pos;
    }

    return -1;
}


//Busca linear sem sentinela
int linearSearchDictionary(Dictionary *T, User data){

    for(int i = 0 ; i<T->size ; i++){

        if(T->V[i].id == data.id) return i;
    }

    return -1;
}



//Função par gerar um caso de teste preechendo um dicionário de 1000 nomes;
void genTestCase(Dictionary *T){

    
    char *N[] = {"Fernanda Cardoso", "Helena Barbosa", "Eduardo Lima", "Vanessa Iglesias", "Fernanda Pereira", "Nicolas Nascimento", "Joana Nascimento", "Joana Oliveira", "Eduardo Cardoso", "Ana Klein", "Mariana Gomes", "Lucas Ferreira", "Thiago Jesus", "Bruno Iglesias", "Vanessa Esteves", "Rafael Nascimento", "Daniel Dias", "Lucas Almeida", "Fernanda Jesus", "Ana Silva", "Thiago Ribeiro", "Sofia Ribeiro", "Quiteria Lima", "Helena Queiroz", "Bruno Moraes", "Thiago Dias", "Daniel Esteves", "Daniel Almeida", "Rafael Dias", "Paulo Gomes", "Thiago Almeida", "Quiteria Barbosa", "Fernanda Almeida", "Sofia Cardoso", "Rafael Teixeira", "Fernanda Ferreira", "Bruno Lima", "Paulo Lima", "Eduardo Queiroz", "Sofia Henrique", "Igor Dias", "Carla Gomes", "Thiago Silva", "Daniel Lima", "Quiteria Barbosa", "Quiteria Klein", "Gabriel Klein", "Vanessa Esteves", "Ana Jesus", "Vanessa Barbosa", "Sofia Jesus", "Gabriel Jesus", "Eduardo Nascimento", "Bruno Iglesias", "Igor Pereira", "Carla Almeida", "Sofia Gomes", "Nicolas Teixeira", "Ana Silva", "Paulo Iglesias", "Quiteria Oliveira", "Carla Ferreira", "Thiago Queiroz", "Helena Ferreira", "Sofia Ribeiro", "Quiteria Jesus", "Ana Henrique", "Sofia Nascimento", "Olivia Klein", "Carla Gomes", "Gabriel Teixeira", "Fernanda Gomes", "Helena Klein", "Quiteria Ferreira", "Quiteria Gomes", "Thiago Klein", "Olivia Lima", "Gabriel Esteves", "Carla Jesus", "Eduardo Jesus", "Lucas Dias", "Quiteria Oliveira", "Paulo Moraes", "Vanessa Barbosa", "Thiago Ribeiro", "Helena Nascimento", "Ana Esteves", "Mariana Jesus", "Nicolas Barbosa", "Quiteria Almeida", "Quiteria Ribeiro", "Joana Henrique", "Gabriel Nascimento", "Vanessa Teixeira", "Vanessa Ribeiro", "Igor Esteves", "Olivia Silva", "Helena Ferreira", "Quiteria Gomes", "Gabriel Moraes", "Fernanda Klein", "Gabriel Lima", "Igor Oliveira", "Joana Klein", "Eduardo Nascimento", "Rafael Pereira", "Carla Gomes", "Paulo Queiroz", "Nicolas Nascimento", "Olivia Henrique", "Sofia Moraes", "Vanessa Gomes", "Quiteria Moraes", "Mariana Oliveira", "Rafael Teixeira", "Bruno Silva", "Quiteria Iglesias", "Fernanda Ferreira", "Helena Almeida", "Eduardo Barbosa", "Bruno Almeida", "Vanessa Oliveira", "Thiago Henrique", "Carla Silva", "Rafael Queiroz", "Helena Esteves", "Vanessa Cardoso", "Joana Almeida", "Joana Jesus", "Rafael Teixeira", "Sofia Pereira", "Gabriel Lima", "Vanessa Henrique", "Lucas Almeida", "Igor Cardoso", "Paulo Almeida", "Gabriel Klein", "Daniel Barbosa", "Carla Barbosa", "Lucas Pereira", "Ana Oliveira", "Olivia Pereira", "Olivia Barbosa", "Quiteria Klein", "Helena Oliveira", "Bruno Ribeiro", "Gabriel Moraes", "Carla Henrique", "Quiteria Barbosa", "Nicolas Moraes", "Sofia Klein", "Nicolas Pereira", "Fernanda Gomes", "Carla Almeida", "Eduardo Esteves", "Gabriel Almeida", "Mariana Esteves", "Thiago Klein", "Helena Queiroz", "Sofia Moraes", "Mariana Silva", "Thiago Cardoso", "Lucas Jesus", "Nicolas Almeida", "Olivia Pereira", "Joana Nascimento", "Fernanda Henrique", "Eduardo Iglesias", "Mariana Henrique", "Paulo Ferreira", "Daniel Teixeira", "Quiteria Lima", "Fernanda Dias", "Gabriel Dias", "Daniel Cardoso", "Eduardo Cardoso", "Ana Silva", "Mariana Iglesias", "Fernanda Lima", "Ana Pereira", "Vanessa Iglesias", "Daniel Oliveira", "Mariana Pereira", "Paulo Klein", "Carla Klein", "Sofia Jesus", "Olivia Teixeira", "Quiteria Teixeira", "Lucas Klein", "Ana Dias", "Lucas Iglesias", "Joana Barbosa", "Paulo Klein", "Rafael Iglesias", "Igor Esteves", "Vanessa Henrique", "Vanessa Almeida", "Rafael Esteves", "Vanessa Ferreira", "Helena Queiroz", "Daniel Ferreira", "Gabriel Dias", "Thiago Barbosa", "Rafael Cardoso", "Lucas Pereira", "Helena Pereira", "Thiago Teixeira", "Paulo Silva", "Fernanda Cardoso", "Quiteria Cardoso", "Eduardo Klein", "Mariana Klein", "Helena Teixeira", "Paulo Pereira", "Ana Henrique", "Quiteria Lima", "Helena Klein", "Paulo Klein", "Fernanda Barbosa", "Carla Almeida", "Fernanda Iglesias", "Carla Nascimento", "Gabriel Teixeira", "Vanessa Ferreira", "Paulo Silva", "Fernanda Ribeiro", "Helena Pereira", "Daniel Dias", "Nicolas Moraes", "Eduardo Moraes", "Eduardo Ferreira", "Gabriel Nascimento", "Fernanda Barbosa", "Rafael Ribeiro", "Paulo Klein", "Igor Lima", "Igor Lima", "Igor Gomes", "Sofia Queiroz", "Bruno Almeida", "Fernanda Gomes", "Carla Dias", "Joana Jesus", "Paulo Teixeira", "Igor Iglesias", "Daniel Oliveira", "Bruno Lima", "Nicolas Gomes", "Fernanda Iglesias", "Sofia Lima", "Ana Nascimento", "Gabriel Nascimento", "Mariana Lima", "Lucas Cardoso", "Paulo Almeida", "Helena Queiroz", "Helena Jesus", "Gabriel Lima", "Carla Silva", "Bruno Klein", "Helena Silva", "Carla Ferreira", "Bruno Henrique", "Fernanda Dias", "Eduardo Oliveira", "Helena Queiroz", "Nicolas Dias", "Daniel Ferreira", "Helena Dias", "Fernanda Almeida", "Bruno Nascimento", "Paulo Moraes", "Paulo Gomes", "Olivia Teixeira", "Fernanda Lima", "Quiteria Oliveira", "Joana Almeida", "Paulo Pereira", "Bruno Jesus", "Paulo Ferreira", "Eduardo Almeida", "Rafael Ribeiro", "Joana Moraes", "Joana Klein", "Ana Ferreira", "Eduardo Henrique", "Paulo Barbosa", "Vanessa Klein", "Joana Iglesias", "Vanessa Queiroz", "Quiteria Nascimento", "Helena Pereira", "Rafael Lima", "Daniel Dias", "Daniel Barbosa", "Bruno Cardoso", "Nicolas Esteves", "Igor Almeida", "Nicolas Ribeiro", "Nicolas Silva", "Carla Moraes", "Lucas Almeida", "Paulo Gomes", "Mariana Teixeira", "Quiteria Pereira", "Vanessa Pereira", "Eduardo Lima", "Mariana Henrique", "Mariana Almeida", "Olivia Teixeira", "Olivia Silva", "Nicolas Ferreira", "Vanessa Nascimento", "Fernanda Nascimento", "Olivia Gomes", "Thiago Ferreira", "Nicolas Iglesias", "Joana Lima", "Eduardo Moraes", "Vanessa Ribeiro", "Sofia Moraes", "Helena Jesus", "Helena Almeida", "Bruno Iglesias", "Fernanda Oliveira", "Helena Ferreira", "Fernanda Moraes", "Paulo Almeida", "Thiago Almeida", "Fernanda Esteves", "Sofia Ferreira", "Thiago Queiroz", "Lucas Ferreira", "Olivia Pereira", "Eduardo Gomes", "Helena Henrique", "Daniel Ribeiro", "Eduardo Moraes", "Vanessa Ribeiro", "Paulo Nascimento", "Lucas Henrique", "Vanessa Henrique", "Ana Moraes", "Helena Nascimento", "Rafael Klein", "Gabriel Lima", "Igor Nascimento", "Carla Esteves", "Joana Oliveira", "Lucas Queiroz", "Helena Jesus", "Sofia Pereira", "Quiteria Barbosa", "Sofia Dias", "Mariana Dias", "Mariana Moraes", "Helena Ribeiro", "Sofia Barbosa", "Carla Moraes", "Sofia Oliveira", "Sofia Oliveira", "Lucas Gomes", "Mariana Gomes", "Quiteria Henrique", "Thiago Almeida", "Joana Ferreira", "Rafael Moraes", "Paulo Teixeira", "Sofia Almeida", "Joana Ribeiro", "Joana Silva", "Fernanda Cardoso", "Igor Moraes", "Ana Ferreira", "Ana Esteves", "Joana Esteves", "Carla Esteves", "Paulo Cardoso", "Igor Pereira", "Carla Almeida", "Helena Cardoso", "Eduardo Ribeiro", "Eduardo Teixeira", "Rafael Queiroz", "Ana Ribeiro", "Vanessa Ribeiro", "Vanessa Almeida", "Ana Klein", "Eduardo Nascimento", "Rafael Henrique", "Joana Teixeira", "Carla Lima", "Thiago Jesus", "Nicolas Silva", "Lucas Silva", "Rafael Pereira", "Quiteria Ribeiro", "Ana Gomes", "Vanessa Ribeiro", "Daniel Cardoso", "Ana Gomes", "Olivia Henrique", "Helena Lima", "Bruno Silva", "Joana Teixeira", "Daniel Cardoso", "Daniel Gomes", "Ana Queiroz", "Nicolas Queiroz", "Bruno Jesus", "Fernanda Henrique", "Lucas Jesus", "Sofia Dias", "Thiago Teixeira", "Thiago Nascimento", "Daniel Oliveira", "Joana Moraes", "Nicolas Silva", "Sofia Jesus", "Helena Oliveira", "Igor Dias", "Nicolas Jesus", "Helena Ferreira", "Carla Moraes", "Quiteria Queiroz", "Vanessa Cardoso", "Nicolas Gomes", "Paulo Cardoso", "Igor Ribeiro", "Fernanda Nascimento", "Eduardo Cardoso", "Rafael Queiroz", "Eduardo Gomes", "Vanessa Teixeira", "Igor Dias", "Fernanda Teixeira", "Olivia Pereira", "Bruno Barbosa", "Bruno Esteves", "Olivia Jesus", "Eduardo Ribeiro", "Olivia Gomes", "Thiago Nascimento", "Gabriel Teixeira", "Paulo Dias", "Paulo Pereira", "Gabriel Moraes", "Gabriel Gomes", "Rafael Queiroz", "Fernanda Queiroz", "Gabriel Dias", "Paulo Jesus", "Eduardo Almeida", "Rafael Cardoso", "Mariana Almeida", "Eduardo Esteves", "Igor Barbosa", "Ana Almeida", "Lucas Teixeira", "Thiago Pereira", "Mariana Esteves", "Eduardo Cardoso", "Paulo Nascimento", "Gabriel Klein", "Ana Barbosa", "Thiago Dias", "Sofia Gomes", "Rafael Ferreira", "Mariana Lima", "Mariana Cardoso", "Ana Klein", "Igor Teixeira", "Rafael Nascimento", "Thiago Lima", "Igor Henrique", "Mariana Henrique", "Lucas Silva", "Lucas Lima", "Ana Silva", "Eduardo Dias", "Carla Nascimento", "Carla Moraes", "Carla Henrique", "Paulo Gomes", "Gabriel Jesus", "Lucas Teixeira", "Rafael Queiroz", "Bruno Ferreira", "Ana Dias", "Vanessa Moraes", "Gabriel Henrique", "Bruno Oliveira", "Joana Silva", "Joana Oliveira", "Mariana Pereira", "Igor Teixeira", "Gabriel Almeida", "Quiteria Cardoso", "Joana Oliveira", "Vanessa Nascimento", "Olivia Pereira", "Helena Silva", "Ana Moraes", "Bruno Gomes", "Olivia Silva", "Nicolas Almeida", "Mariana Moraes", "Paulo Queiroz", "Sofia Pereira", "Helena Dias", "Bruno Barbosa", "Daniel Dias", "Ana Pereira", "Olivia Moraes", "Helena Silva", "Thiago Teixeira", "Igor Esteves", "Ana Moraes", "Bruno Moraes", "Ana Ferreira", "Carla Queiroz", "Lucas Iglesias", "Olivia Barbosa", "Gabriel Teixeira", "Vanessa Oliveira", "Eduardo Ferreira", "Igor Barbosa", "Quiteria Ferreira", "Joana Barbosa", "Paulo Ferreira", "Helena Teixeira", "Igor Oliveira", "Ana Moraes", "Joana Ferreira", "Sofia Teixeira", "Paulo Moraes", "Nicolas Ribeiro", "Lucas Jesus", "Olivia Silva", "Fernanda Gomes", "Lucas Dias", "Igor Henrique", "Bruno Jesus", "Daniel Jesus", "Olivia Gomes", "Fernanda Lima", "Olivia Jesus", "Nicolas Iglesias", "Joana Silva", "Mariana Barbosa", "Bruno Ferreira", "Rafael Teixeira", "Mariana Almeida", "Nicolas Almeida", "Fernanda Esteves", "Helena Jesus", "Joana Pereira", "Carla Iglesias", "Gabriel Nascimento", "Bruno Jesus", "Thiago Cardoso", "Olivia Cardoso", "Thiago Silva", "Nicolas Barbosa", "Eduardo Ferreira", "Ana Cardoso", "Nicolas Klein", "Mariana Cardoso", "Mariana Moraes", "Helena Lima", "Joana Teixeira", "Gabriel Lima", "Lucas Ferreira", "Daniel Nascimento", "Fernanda Gomes", "Carla Henrique", "Igor Ferreira", "Helena Klein", "Rafael Esteves", "Olivia Dias", "Rafael Cardoso", "Olivia Barbosa", "Quiteria Henrique", "Fernanda Gomes", "Mariana Ferreira", "Thiago Silva", "Fernanda Queiroz", "Fernanda Ferreira", "Joana Esteves", "Thiago Barbosa", "Bruno Dias", "Bruno Pereira", "Helena Gomes", "Bruno Queiroz", "Eduardo Henrique", "Nicolas Ferreira", "Rafael Ribeiro", "Igor Pereira", "Fernanda Oliveira", "Bruno Almeida", "Sofia Lima", "Paulo Barbosa", "Rafael Iglesias", "Joana Cardoso", "Helena Nascimento", "Joana Gomes", "Daniel Ribeiro", "Olivia Oliveira", "Quiteria Teixeira", "Daniel Lima", "Olivia Cardoso", "Carla Silva", "Lucas Gomes", "Olivia Nascimento", "Bruno Ferreira", "Ana Klein", "Vanessa Nascimento", "Nicolas Jesus", "Lucas Moraes", "Thiago Dias", "Igor Teixeira", "Olivia Teixeira", "Sofia Klein", "Bruno Queiroz", "Mariana Pereira", "Joana Queiroz", "Vanessa Iglesias", "Daniel Gomes", "Daniel Gomes", "Lucas Gomes", "Olivia Jesus", "Gabriel Dias", "Fernanda Silva", "Carla Nascimento", "Gabriel Nascimento", "Joana Barbosa", "Daniel Gomes", "Olivia Teixeira", "Vanessa Dias", "Quiteria Pereira", "Helena Jesus", "Fernanda Dias", "Gabriel Nascimento", "Bruno Moraes", "Gabriel Dias", "Carla Ferreira", "Helena Klein", "Olivia Nascimento", "Vanessa Ferreira", "Olivia Oliveira", "Joana Silva", "Ana Moraes", "Fernanda Teixeira", "Nicolas Iglesias", "Olivia Pereira", "Lucas Cardoso", "Daniel Lima", "Eduardo Oliveira", "Igor Almeida", "Eduardo Queiroz", "Daniel Lima", "Eduardo Teixeira", "Olivia Ferreira", "Vanessa Pereira", "Lucas Dias", "Nicolas Klein", "Joana Jesus", "Igor Jesus", "Vanessa Pereira", "Joana Moraes", "Joana Klein", "Lucas Gomes", "Ana Jesus", "Ana Klein", "Vanessa Teixeira", "Nicolas Jesus", "Joana Pereira", "Bruno Ferreira", "Rafael Moraes", "Paulo Queiroz", "Paulo Jesus", "Bruno Teixeira", "Igor Pereira", "Nicolas Teixeira", "Quiteria Oliveira", "Joana Silva", "Quiteria Gomes", "Igor Teixeira", "Paulo Klein", "Eduardo Henrique", "Nicolas Jesus", "Ana Ferreira", "Thiago Oliveira", "Carla Almeida", "Quiteria Esteves", "Paulo Silva", "Joana Silva", "Carla Barbosa", "Gabriel Lima", "Mariana Silva", "Bruno Ribeiro", "Vanessa Esteves", "Nicolas Lima", "Mariana Moraes", "Helena Gomes", "Quiteria Ferreira", "Joana Cardoso", "Thiago Cardoso", "Lucas Silva", "Thiago Ferreira", "Vanessa Moraes", "Helena Nascimento", "Gabriel Cardoso", "Igor Silva", "Rafael Ribeiro", "Olivia Esteves", "Rafael Esteves", "Sofia Nascimento", "Paulo Cardoso", "Rafael Dias", "Olivia Esteves", "Sofia Gomes", "Olivia Ferreira", "Helena Moraes", "Helena Nascimento", "Ana Almeida", "Helena Lima", "Helena Oliveira", "Joana Gomes", "Ana Dias", "Paulo Pereira", "Joana Gomes", "Ana Ferreira", "Vanessa Moraes", "Fernanda Barbosa", "Rafael Esteves", "Eduardo Pereira", "Lucas Teixeira", "Lucas Oliveira", "Thiago Oliveira", "Vanessa Dias", "Bruno Henrique", "Mariana Klein", "Quiteria Lima", "Olivia Lima", "Carla Henrique", "Joana Moraes", "Rafael Jesus", "Joana Ribeiro", "Bruno Ribeiro", "Sofia Ribeiro", "Fernanda Gomes", "Lucas Gomes", "Thiago Pereira", "Nicolas Pereira", "Ana Cardoso", "Bruno Teixeira", "Sofia Almeida", "Gabriel Moraes", "Fernanda Esteves", "Nicolas Barbosa", "Daniel Dias", "Olivia Moraes", "Mariana Nascimento", "Bruno Iglesias", "Thiago Oliveira", "Paulo Lima", "Olivia Henrique", "Bruno Ribeiro", "Helena Silva", "Lucas Teixeira", "Eduardo Almeida", "Joana Barbosa", "Quiteria Iglesias", "Quiteria Jesus", "Fernanda Ferreira", "Quiteria Almeida", "Thiago Ribeiro", "Nicolas Jesus", "Eduardo Jesus", "Thiago Silva", "Thiago Esteves", "Joana Moraes", "Paulo Cardoso", "Fernanda Moraes", "Daniel Klein", "Igor Barbosa", "Mariana Ferreira", "Gabriel Jesus", "Olivia Esteves", "Daniel Oliveira", "Quiteria Jesus", "Thiago Henrique", "Joana Klein", "Fernanda Jesus", "Rafael Lima", "Rafael Henrique", "Vanessa Jesus", "Thiago Almeida", "Lucas Ribeiro", "Joana Nascimento", "Nicolas Henrique", "Joana Dias", "Carla Nascimento", "Paulo Ribeiro", "Igor Queiroz", "Carla Cardoso", "Paulo Queiroz", "Thiago Teixeira", "Gabriel Jesus", "Paulo Pereira", "Gabriel Dias", "Igor Gomes", "Nicolas Henrique", "Fernanda Almeida", "Olivia Klein", "Ana Klein", "Helena Teixeira", "Mariana Jesus", "Eduardo Dias", "Igor Jesus", "Paulo Silva", "Daniel Gomes", "Thiago Pereira", "Olivia Moraes", "Mariana Lima", "Daniel Almeida", "Helena Silva", "Rafael Queiroz", "Gabriel Lima", "Eduardo Jesus", "Sofia Dias", "Rafael Moraes", "Thiago Teixeira", "Joana Lima", "Helena Pereira", "Fernanda Cardoso", "Ana Queiroz", "Rafael Silva", "Ana Moraes", "Quiteria Teixeira", "Nicolas Dias", "Olivia Ferreira", "Fernanda Nascimento", "Helena Almeida", "Vanessa Lima", "Joana Barbosa", "Quiteria Dias", "Rafael Silva", "Mariana Cardoso", "Carla Teixeira", "Ana Lima", "Thiago Dias", "Bruno Almeida", "Igor Oliveira", "Carla Esteves", "Lucas Queiroz", "Igor Klein", "Nicolas Ribeiro", "Daniel Klein", "Bruno Oliveira", "Olivia Teixeira", "Daniel Cardoso", "Nicolas Gomes", "Fernanda Silva", "Gabriel Barbosa", "Daniel Ribeiro", "Paulo Esteves", "Thiago Cardoso", "Ana Barbosa", "Joana Lima", "Rafael Queiroz", "Rafael Ferreira", "Ana Esteves", "Quiteria Gomes", "Quiteria Teixeira", "Nicolas Klein", "Nicolas Oliveira", "Nicolas Ferreira", "Helena Oliveira", "Helena Oliveira", "Mariana Cardoso", "Lucas Esteves", "Ana Moraes", "Fernanda Teixeira", "Nicolas Henrique", "Ana Teixeira", "Thiago Ferreira", "Paulo Esteves", "Mariana Oliveira", "Lucas Gomes", "Rafael Barbosa", "Igor Dias", "Joana Ribeiro", "Fernanda Barbosa", "Helena Nascimento", "Quiteria Moraes", "Sofia Queiroz", "Thiago Henrique", "Eduardo Henrique", "Lucas Henrique", "Paulo Iglesias", "Quiteria Klein", "Gabriel Ferreira", "Joana Barbosa", "Rafael Almeida", "Olivia Lima", "Eduardo Dias", "Olivia Esteves", "Ana Almeida", "Nicolas Esteves", "Ana Silva", "Nicolas Cardoso", "Quiteria Klein", "Vanessa Henrique", "Vanessa Lima", "Carla Jesus", "Quiteria Oliveira", "Fernanda Moraes", "Bruno Ribeiro", "Carla Oliveira", "Eduardo Ferreira", "Thiago Ribeiro", "Daniel Barbosa", "Ana Pereira", "Lucas Oliveira", "Thiago Queiroz", "Eduardo Klein", "Paulo Ferreira", "Daniel Almeida", "Igor Barbosa", "Sofia Ribeiro", "Mariana Almeida", "Eduardo Almeida", "Eduardo Esteves", "Ana Ferreira", "Paulo Henrique", "Ana Cardoso", "Fernanda Ferreira", "Igor Silva", "Olivia Cardoso", "Quiteria Teixeira", "Lucas Henrique", "Igor Oliveira", "Ana Barbosa", "Olivia Moraes", "Joana Ferreira", "Carla Cardoso", "Daniel Pereira", "Paulo Pereira", "Gabriel Ferreira", "Quiteria Iglesias", "Ana Teixeira", "Ana Iglesias", "Rafael Klein", "Nicolas Dias", "Daniel Ribeiro", "Bruno Silva", "Nicolas Silva", "Carla Klein", "Fernanda Henrique", "Nicolas Esteves", "Carla Klein", "Bruno Esteves", "Vanessa Iglesias", "Carla Gomes", "Helena Pereira", "Lucas Lima", "Nicolas Lima", "Lucas Ribeiro", "Olivia Ribeiro", "Ana Henrique", "Joana Ribeiro", "Sofia Ferreira", "Helena Nascimento", "Igor Pereira", "Eduardo Ferreira", "Gabriel Jesus", "Gabriel Almeida", "Igor Lima", "Quiteria Esteves", "Thiago Gomes", "Lucas Pereira", "Joana Gomes", "Vanessa Ribeiro", "Bruno Cardoso", "Quiteria Esteves", "Joana Queiroz", "Lucas Silva", "Carla Queiroz", "Ana Dias", "Mariana Cardoso", "Quiteria Almeida", "Sofia Henrique", "Daniel Henrique", "Rafael Oliveira", "Lucas Iglesias", "Lucas Queiroz", "Ana Queiroz", "Eduardo Almeida"};
    
    int ids[1000] = {656, 76, 15, 110, 570, 240, 641, 456, 844, 754, 807, 143, 439, 274, 821, 420, 652, 496, 897, 676, 7, 932, 418, 305, 112, 995, 776, 118, 342, 826, 703, 272, 921, 746, 190, 382, 661, 130, 437, 721, 259, 312, 996, 316, 587, 639, 275, 630, 441, 597, 18, 23, 29, 30, 32, 45, 75, 197, 209, 228, 235, 304, 309, 330, 353, 369, 373, 376, 407, 409, 438, 485, 487, 494, 521, 545, 592, 644, 657, 701, 704, 709, 738, 748, 761, 774, 787, 795, 856, 911, 931, 933, 940, 942, 963, 965, 971, 976, 988, 998, 39, 49, 54, 80, 127, 136, 148, 150, 152, 194, 196, 266, 281, 293, 308, 331, 335, 405, 408, 440, 465, 480, 514, 527, 534, 554, 576, 614, 626, 638, 655, 667, 668, 699, 700, 708, 736, 739, 753, 799, 838, 849, 858, 863, 926, 938, 961, 980, 982, 985, 978, 973, 887, 83, 873, 929, 918, 451, 33, 402, 972, 24, 620, 923, 871, 968, 213, 365, 144, 647, 605, 386, 839, 107, 399, 495, 332, 674, 255, 877, 750, 811, 519, 934, 258, 612, 834, 366, 881, 348, 629, 410, 886, 142, 845, 743, 990, 56, 306, 291, 77, 113, 145, 159, 195, 214, 216, 219, 237, 242, 249, 295, 313, 384, 417, 443, 463, 467, 468, 474, 512, 520, 533, 535, 536, 550, 580, 582, 585, 680, 691, 695, 730, 751, 805, 827, 829, 830, 836, 848, 854, 859, 865, 875, 889, 893, 912, 917, 946, 947, 0, 11, 50, 59, 85, 89, 95, 101, 102, 108, 132, 177, 199, 271, 279, 301, 338, 374, 393, 416, 423, 435, 458, 469, 531, 548, 573, 574, 594, 600, 603, 611, 619, 632, 633, 651, 664, 670, 684, 697, 737, 755, 783, 831, 840, 913, 915, 919, 950, 959, 450, 712, 20, 311, 916, 526, 528, 665, 818, 962, 566, 492, 236, 256, 499, 186, 167, 867, 119, 710, 44, 201, 379, 872, 371, 286, 686, 121, 757, 726, 993, 952, 847, 302, 781, 192, 156, 957, 794, 105, 5, 299, 646, 813, 752, 541, 202, 63, 786, 590, 9, 14, 25, 64, 94, 96, 123, 124, 149, 181, 188, 205, 206, 217, 248, 260, 263, 287, 294, 380, 398, 411, 422, 460, 471, 522, 537, 538, 558, 608, 631, 637, 660, 678, 696, 698, 715, 741, 744, 758, 760, 765, 772, 797, 798, 820, 823, 861, 868, 1000, 38, 46, 58, 68, 120, 122, 134, 139, 147, 171, 232, 238, 245, 254, 261, 315, 337, 341, 400, 425, 428, 436, 447, 448, 452, 473, 479, 481, 529, 532, 552, 563, 589, 599, 635, 643, 659, 735, 762, 802, 819, 825, 835, 876, 879, 882, 892, 922, 935, 941, 16, 17, 27, 73, 98, 106, 111, 126, 141, 165, 182, 184, 204, 210, 303, 307, 317, 320, 340, 343, 344, 346, 419, 429, 454, 483, 505, 530, 560, 562, 568, 571, 575, 581, 586, 598, 624, 625, 645, 673, 690, 714, 778, 816, 850, 880, 920, 927, 945, 984, 949, 502, 525, 401, 475, 960, 125, 642, 801, 833, 415, 164, 92, 780, 851, 928, 231, 203, 567, 895, 278, 944, 588, 688, 543, 773, 170, 459, 874, 161, 133, 477, 191, 503, 767, 356, 955, 604, 290, 572, 683, 948, 2, 444, 253, 128, 732, 377, 742, 466, 339, 870, 185, 282, 687, 539, 497, 790, 66, 397, 4, 789, 759, 383, 326, 300, 953, 357, 653, 606, 114, 35, 37, 511, 91, 719, 906, 36, 470, 43, 247, 137, 517, 970, 869, 662, 903, 693, 806, 57, 446, 717, 1, 583, 40, 176, 60, 250, 174, 728, 6, 21, 48, 62, 65, 86, 103, 131, 173, 175, 179, 221, 223, 277, 284, 297, 318, 334, 347, 392, 413, 426, 432, 455, 462, 486, 491, 540, 544, 549, 561, 569, 654, 677, 682, 685, 702, 705, 711, 723, 734, 749, 768, 779, 815, 860, 951, 958, 987, 999, 26, 55, 71, 78, 79, 93, 99, 104, 116, 138, 153, 154, 157, 158, 160, 180, 220, 229, 252, 265, 270, 292, 321, 322, 323, 329, 351, 358, 362, 364, 372, 375, 461, 484, 489, 516, 591, 602, 713, 727, 771, 785, 817, 843, 846, 888, 901, 904, 969, 991, 731, 457, 187, 431, 172, 515, 166, 506, 246, 628, 207, 109, 490, 898, 28, 19, 178, 804, 853, 212, 822, 288, 974, 268, 909, 500, 621, 51, 900, 53, 482, 896, 283, 649, 509, 421, 864, 87, 775, 433, 956, 88, 391, 910, 777, 542, 689, 634, 234, 894, 593, 994, 939, 34, 81, 389, 115, 388, 577, 578, 770, 671, 883, 117, 97, 215, 501, 163, 449, 504, 809, 508, 61, 669, 800, 378, 885, 183, 890, 464, 724, 803, 584, 472, 832, 814, 878, 547, 328, 986, 565, 828, 925, 404, 784, 226, 650, 810, 852, 914, 367, 82, 663, 267, 319, 430, 370, 239, 72, 997, 200, 151, 273, 908, 899, 74, 564, 10, 162, 740, 336, 718, 937, 672, 837, 595, 314, 361, 981, 84, 596, 622, 788, 716, 225, 513, 510, 733, 756, 387, 855, 964, 694, 360, 396, 285, 636, 42, 198, 222, 8, 13, 22, 41, 67, 135, 146, 155, 168, 169, 211, 218, 233, 241, 244, 289, 296, 345, 349, 355, 385, 390, 394, 395, 403, 412, 427, 442, 524, 546, 557, 610, 623, 640, 679, 692, 706, 729, 747, 769, 782, 793, 808, 812, 841, 862, 884, 902, 975, 983, 368, 966, 478, 796, 52, 857, 627, 615, 992, 979, 381, 658, 406, 12, 208, 276, 262, 518, 648, 601, 907, 766, 936, 453, 924, 243, 792, 90, 553, 269, 434, 609, 551, 764, 617, 707, 842, 556, 47, 559, 720, 488, 324, 445, 69, 507, 791, 414, 930, 989, 3, 31, 70, 100, 129, 140, 189, 193, 224, 227, 230, 251, 257, 264, 280, 298, 310, 325, 327, 333, 350, 354, 359, 363, 424, 476, 493, 498, 523, 555, 579, 607, 613, 616, 618, 666, 675, 681, 722, 725, 745, 763, 824, 866, 891, 905, 943, 954, 967, 977};
    
    User data;
    
    for(int i =0 ; i<1000 ; i++){
        
        data.id=ids[i];
        data.name = N[i];
        data.amount = rand()%10000/ (float) ((rand()%5)+1); 
        insertDictionary(T,data);

    }
}




//Função para gerar string resposta da busca
char* genResponse(int pos, Dictionary *T){

    char str1[200];
    char *res = (char*) malloc(sizeof(str1));

    int i =0;

    
    sprintf(str1,"User found !!\n id =%d | name = %s | amount = R$ %0.2f\n", T->V[pos].id, T->V[pos].name , T->V[pos].amount);
    
    
    
    for(i = 0 ; i<200 && str1[i]!='\0';i++){

        res[i] = str1[i];
    }

    res[i] = '\0';

    

   
    return res;
}


//Função ara testar buscas
char* testSearch(int pos, Dictionary *T){
  
        
    if(pos>-1){
       
        return genResponse(pos, T);

    }
    else{
        
        char *resp = "User not found";

        char *c = (char*) malloc(sizeof (char)*50);

        int i = 0;

        while(resp[i]!='\0'){
            c[i]=resp[i];
            i++;
        }

        c[i]='\0';

        return c;
    }

}


void swap(User *a, User *b){
   

    User aux;

    aux = *a;
    

    *a = *b;
    

    *b = aux;


}


void particion(Dictionary *T, int left, int right, int *i, int *j){

    int pivot= T->V[(left+right)/2].id;
    
    (*i) = left;
    (*j) = right;


    do{
        
        while(T->V[*j].id>pivot) (*j)--;

        while(T->V[*i].id<pivot) (*i)++;

        if(*i<=*j){
           
            swap(T->V+(*i), T->V+(*j));

            (*i)++;
            (*j)--;

        }
        
        
        

    }while(*i<=*j);
}

void sorting(Dictionary *T, int left, int right){

    int i , j;

    particion(T,left, right, &i,&j);

    if(i<right) sorting (T,i,right);
    
    if(left<j) sorting (T,left,j);
    
}


void quicksort(Dictionary *T){

    sorting(T, 0 , T->size-1);
}

int main(){

    Dictionary P;
    User d;
    char *res;

    d.id=100;
    

    //Criamos um dicionário que suport 1000 dados do tipo User
    createDictionary(&P,1000);
    
    //Geramos um caso de teste com 1000 dados do tipo usuário
    genTestCase(&P);
    
    //Ordenamos esse dicionário em relação aos ID's para realizar a busca binária
    quicksort(&P);

    //insertDictionary(&P,d);
    
    //Pritamos todo o diconário já ordenado
    printDictionary(&P);
    

    //Realização de Buscas Binárias(Com recursão e sem recursão) e Busca Linear 
    
    d.id=232;
    int pos_test1 = searchDictionary(&P,0,P.size-1,d);
    
    d.id=453;
    int pos_test2 = searchDictionaryNoRecursion(&P,0,P.size-1,d);
    
    d.id=789;
    int pos_test3 = linearSearchDictionary(&P, d);

    d.id=8780;
    int pos_test4 = searchDictionary(&P,0,P.size-1,d);
    
    d.id=1001;
    int pos_test5 = searchDictionaryNoRecursion(&P,0,P.size-1,d);
    
    d.id=-129;
    int pos_test6 = linearSearchDictionary(&P, d);
    
        

    printf("\n\nTESTES PARA ID'S QUE EXISTEM NO DICIONARIO DE DADOS\n\n");
    printf("--------------------------------------------------------\n\n");
    
    res = testSearch(pos_test1,&P);

    printf("TESTE- Busca binária com recursão =\n%s\n", res);
    printf("----------------------------------------\n");
    
    free(res);

    res = testSearch(pos_test2,&P);

    printf("TESTE- Busca binária sem recursão =\n%s\n",res);
    
    free(res);

    printf("----------------------------------------\n");
    
    res = testSearch(pos_test3,&P);

    printf("TESTE- Busca linear =\n%s\n", res);
    
    free(res);

    printf("----------------------------------------\n\n\n");


    printf("TESTES PARA ID'S QUE NAO EXISTEM NO DICIONARIO DE DADOS\n\n");
    printf("--------------------------------------------------------\n\n");
    
    res = testSearch(pos_test4,&P);

    printf("TESTE- Busca binária com recursão =\n%s\n", res);
    printf("----------------------------------------\n");
    
    free(res);
    res = testSearch(pos_test5,&P);

    printf("TESTE- Busca binária sem recursão =\n%s\n",res);
    
    printf("----------------------------------------\n");
    
    free(res);
    res = testSearch(pos_test6,&P);

    printf("TESTE- Busca linear =\n%s\n", res);
    
    printf("----------------------------------------\n");
     
    free(res);    
    clearDictionary(&P);
}

