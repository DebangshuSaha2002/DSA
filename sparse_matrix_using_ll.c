#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *next;
};

void create_new_node(struct Node** start, int non_zero_element,int row_index, int column_index )
{
	struct Node *temp, *r;
	temp = *start;
	if (temp == NULL)
    {
		temp = (struct Node *) malloc (sizeof(struct Node));
		temp->value = non_zero_element;
		temp->row_position = row_index;
		temp->column_postion = column_index;
		temp->next = NULL;
		*start = temp;
	}
	else
	{
		while (temp->next != NULL)
        {
			temp = temp->next;
        }
		r = (struct Node *) malloc (sizeof(struct Node));
		r->value = non_zero_element;
		r->row_position = row_index;
		r->column_postion = column_index;
		r->next = NULL;
		temp->next = r;
	}
}

void PrintList(struct Node* start)
{
	struct Node *temp, *r, *s;
	temp = r = s = start;

	printf("row_position: ");
	while(temp != NULL)
	{
		printf("%d ", temp->row_position);
		temp = temp->next;
	}
	printf("\n");

	printf("column_postion: ");
	while(r != NULL)
	{
		printf("%d ", r->column_postion);
		r = r->next;
	}
	printf("\n");
	printf("Value: ");
	while(s != NULL)
	{
		printf("%d ", s->value);
		s = s->next;
	}
	printf("\n");
}


int main()
{
    int m,n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&m,&n);
	int sparseMatric[m][n];

    printf("Enter elements:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&sparseMatric[i][j]);
        }
    }

	struct Node* start = NULL;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)

			if (sparseMatric[i][j] != 0)
				create_new_node(&start, sparseMatric[i][j], i, j);

	PrintList(start);

	return 0;
}