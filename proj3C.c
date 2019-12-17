
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 10

typedef struct
{
	char *strings[QUEUE_SIZE];
	int back;
	int front;
	int size;
} Queue;

void InitializeQueue(Queue *q)
{
	q->front = 0;
	q->back = 0;
	q->size = 0;
}

char *Dequeue(Queue *q)
{
	if (q->size <= 0)
	{
		/* printf("ERROR: cannot dequeue there is nothing to remove\n"); */
		return '\0';
	}
	if (q->front == QUEUE_SIZE-1)
	{
		q->front = 0;
	}
	char *x = q->strings[q->front];
	q->front++;
	q->size--;
	return x;
}

void Enqueue(Queue *q, char *x)
{
	if (q->size >= QUEUE_SIZE)
	{
		printf("ERROR: cannot enqueue, at max capacity\n");
		exit(EXIT_FAILURE);
	}
	q->strings[q->back] = x;
	q->back++;
	q->size++;
	if (q->back == QUEUE_SIZE-1)
	{
		q->back = 0;
	}
}

void *Front(Queue *q)
{
	void *beg;
	if(q->size == 0)
	{
		beg = NULL;
		return beg;
	}
	else
	{
		beg = q->strings[q->front];
	}
	return beg;
}


void
PrintQueue(Queue *q)
{
    int i;
    printf("Printing queue %p\n", q);
    printf("\tThe index for the front of the queue is %d\n", q->front);
    printf("\tThe index for the back of the queue is %d\n", q->back);
    if (q->front == q->back)
    {
        printf("\tThe queue is empty.\n");
        return;
    }
    int back = q->back;
    if (q->back < q->front)
    {
        // wrapped around, so modify indexing 
        back += QUEUE_SIZE;
    }

    for (i = q->front ; i < back ; i++)
    {
        printf("\t\tEntry[%d] = \"%s\"\n", i%QUEUE_SIZE, q->strings[i%QUEUE_SIZE]);
    }
}


void
PrettyPrintQueue(Queue *q, char *type)
{
    if (Front(q) == NULL)
    {
        printf("No unmatched entries for %s\n", type);
    }
    else
    {
        char *s;
        printf("Unmatched %s:\n", type);
        while ((s = Dequeue(q)))
        {
            printf("\t%s\n", s);
        }
    }
}

char *NewString(char *s)
{
    int len = strlen(s);
    char *rv = malloc(len);
    strcpy(rv, s);
    rv[len-1] = '\0'; /* take out newline */
    return rv;
}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Not enough arguments were given");
		exit(EXIT_FAILURE);
	}
    	Queue q;
    	Queue male_donors;
    	Queue female_donors;
    	Queue male_recipients;
    	Queue female_recipients;
    	Queue hospitals;
    	InitializeQueue(&q);
    	InitializeQueue(&male_donors);
    	InitializeQueue(&female_donors);
    	InitializeQueue(&male_recipients);
    	InitializeQueue(&female_recipients);
    	InitializeQueue(&hospitals);



  	FILE *f_in;
        f_in = fopen(argv[1], "r");
	char line[256];
	int linenumber = 0;
	while (fgets(line, 256, f_in) != NULL)
	{
		/*
		 printf("%d: %s", linenumber++, line); 
		*/

		if (line[0] == 'H')
		{
			Enqueue(&hospitals, NewString(line+2));
		}
		if(line[0] == 'R' && line[2] == 'F')
		{
			Enqueue(&female_recipients, NewString(line+4));
		}
		if(line[0] == 'D' && line[2] == 'F')
		{
			Enqueue(&female_donors, NewString(line+4));
		}
		if(line[0] == 'D' && line[2] == 'M')
		{
			Enqueue(&male_donors, NewString(line+4));
		}
		if(line[0] == 'R' && line[2] == 'M')
		{
			Enqueue(&male_recipients, NewString(line+4));
		}
		if(female_donors.size > 0 && female_recipients.size > 0 && hospitals.size > 0)
		{
    			printf("MATCH: %s donates to %s at hospital %s\n", Dequeue(&female_donors), Dequeue(&female_recipients), Dequeue(&hospitals));
		}	
		if(male_donors.size > 0 && male_recipients.size > 0 && hospitals.size > 0)
		{
    			printf("MATCH: %s donates to %s at hospital %s\n", Dequeue(&male_donors), Dequeue(&male_recipients), Dequeue(&hospitals));
		}
	}
    	PrettyPrintQueue(&female_donors, "female donors");
    	PrettyPrintQueue(&female_recipients, "female recipients");
    	PrettyPrintQueue(&male_donors, "male donors");
    	PrettyPrintQueue(&male_recipients, "male recipients");
    	PrettyPrintQueue(&hospitals, "hospitals");
}
