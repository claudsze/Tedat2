#include "file_utils.h"
#include "stack.h"
#include "vertex.h"

#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 20

Vertex **readFile(const char *filename, int *size);
void vertex_array_free(Vertex **vertex, int size);
Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout);

int main(int argc, char *argv[]){

    Stack *stack1=NULL, *stack2=NULL, *stack3=NULL;
    Vertex **vertex1=NULL, **vertex2=NULL;
    int size1, size2, i;

    stack1 =stack_init();
    if(!stack1){
        return -1;
    }
    vertex1=readFile(argv[1], &size1);
    if(!vertex1){
        stack_free(stack1);
        return -1;
    }
    for(i=0; i<size1; i++){
        stack_push(stack1, &vertex1[i]);
    }

    fprintf(stdout, "Ranking 0: \n");
    stack_print(stdout, stack1, vertex_print);

    stack2 =stack_init();
    if(!stack2){
        stack_free(stack1);
        vertex_array_free(vertex1, size1);
        return -1;
    }
    vertex2=readFile(argv[2], &size2);
    if(!vertex2){
        stack_free(stack1);
        vertex_array_free(vertex1, size1);
        stack_free(stack2);
        return -1;
    }
    for(i=0; i<size2; i++){
        stack_push(stack2, &vertex2[i]);
    }

    fprintf(stdout, "Ranking 1: \n");
    stack_print(stdout, stack2, vertex_print);

    stack3=stack_init();
    if(!stack3){
        stack_free(stack1);
        vertex_array_free(vertex1, size1);
        stack_free(stack2);
        free(vertex2);/**/
        return -1;
    }
    if(mergeStacks(stack1, stack2, stack3)==ERROR){
        stack_free(stack1);
        vertex_array_free(vertex1, size1);
        stack_free(stack2);
        vertex_array_free(vertex2, size2);
        stack_free(stack3);
        return -1;
    }
    fprintf(stdout, "Joint Ranking: \n");
    stack_print(stdout, stack3, vertex_print);

    vertex_array_free(vertex1, size1);
    vertex_array_free(vertex2, size2);

    stack_free(stack1);
    stack_free(stack2);
    stack_free(stack3);
    return 0;
}

Vertex **readFile(const char *filename, int *size){
    FILE *fich=NULL;
    int n_vertex, i=0;
    Vertex **array=NULL;
    char str[STR_SIZE];

    fich=fopen(filename, "r");
    if(!fich){
        return NULL;
    }
    
    fscanf(fich, "%d", &n_vertex);
    array=(Vertex**)calloc(n_vertex, sizeof(Vertex*));
    if(!array){
        fclose(fich);
        return NULL;
    }
    for(i=0; i<n_vertex; i++){
        if(!fgets(str, STR_SIZE, fich)){
            return NULL;
        }
        array[i]=vertex_initFromString(str);
    }

    *size=n_vertex;
    fclose(fich);
    return array;
}

void vertex_array_free(Vertex **vertex, int size){
    int i;

    for(i=0; i<size; i++){
        vertex_free(vertex[i]);
    }
    free(vertex);
}

Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout)
{
    void *e=NULL;
    Stack *ps=NULL;

    if (!sin1 || !sin2 || !sout )
    {
        return ERROR;
    }
    
    while ((stack_isEmpty(sin1)==FALSE) && (stack_isEmpty(sin2)==FALSE))
    {
        if (*(float *)stack_top (sin1) > *(float *)stack_top (sin2))
        {
            e=stack_pop(sin1);
            if (!e)
            {
                return ERROR;
            }
            
        } else {
            e=stack_pop(sin2);
            if (!e)
            {
                return ERROR;
            }
        }
        stack_push(sout, e);
    }

    /* Detect the non-empy stack */
    if (stack_isEmpty(sin1)==TRUE)
    {
        ps=sin2;
        if (!ps)
        {
            return ERROR;
        }
    } else 
    {
        ps=sin1;
        if (!ps)
        {
            return ERROR;
        }
    }
     /*Pop from the non-empty stack */
    while (stack_isEmpty(ps)==FALSE)
    {
        e=stack_pop(ps);
        if (!e)
        {
            return ERROR;
        }
        stack_push(sout, e);
    }
    
    return OK;
}
