
//Simulation of FCFS Scheduling algorithm used in Operating systems//
//Fixed time slice of 2 is used.Process queue is implemented a sLinked list//
//The program is tuned for user specified number of processes and Buurst times need to be entered//


#include <stdio.h>
#include <iostream>
#include <malloc.h>


struct node
{
	int arrival;
	int burst;
	int priority;
	int turnaround;
	int waiting;
	int finish;
	int name;

	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;


int empty()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

void append (struct node *temp)
{			
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next=NULL;
	}
	else
	{ struct node *t,*previous;
	    if (head->priority>temp->priority)
	    {
	    	temp->next=head;
	    	head =temp;
	    	return ;
		}
		previous=head;
		t=head->next;
		while(t!=NULL && t->priority <= temp->priority)
		{
			previous=t;
			t=t->next;
		}
		temp -> next = t;
		previous->next = temp;
		return ; 
	}
}

struct node* serve ()
{
	struct node *temp;
	if (!empty())
	{
		temp = head;
		head = head -> next;

		return temp;			
	}
	else
	{
		//std::cout<<"Ready q is empty"<<"\n";
		temp = new(node);
		temp -> name = 0;
		return temp;
	}
}	

int main()
{
	int max;

	struct node *p[10];
	struct node *exe;

	int period = 0;
	int count = 0;
	int i;
	int choice;

	double totalWaiting = 0;
	double avgWaiting;
	
	scanf("%d",&max);
	
	
	
	 for (i = 0; i < max; i++)
		{	p[i] =new(node);
			p[i] -> turnaround = 0;
			p[i] -> waiting = 0;
			p[i] -> finish = 0;
			p[i] -> name = i + 1;
			p[i] -> next = NULL;
		}

			for (i = 0; i < max; i++)
			{
			//	std::cin>>p[i] -> arrival;
				scanf("%d",&p[i]->arrival);
			}
	
		for (i = 0; i < max; i++)
		{
		//	std::cin>>p[i] -> burst; 
			scanf("%d",&p[i]->burst);
		}
		for (i = 0; i < max; i++)
		{
		//	std::cin>>p[i] -> burst; 
			scanf("%d",&p[i]->priority);
		}
	
		
		int t=0;
	while (count < max)
		{
				while(t < max && p[t]->arrival <= period ) 
				{					
						append (p[t]);
						t=t+1;
				}
			exe = new(node);
			exe = serve();
        //    getchar();
			if (exe -> name != 0)
			{
					     period=period+exe->burst;
						exe -> finish = period;
						exe -> turnaround = exe -> finish - exe -> arrival;
						exe -> waiting = exe -> turnaround - exe -> burst;

						count ++;

						for (i = 0; i < max; i++)
						{
							if (p[i] -> name == exe -> name)
							{
								p[i] = exe;
							}
						}


						
					
			} 
			else
			{
								

				period = period + 1;
									
			}		
		} 

	
		int totalturnaround=0;
		for (i = 0; i < max; i++)
		{totalWaiting = totalWaiting + p[i] -> waiting;
		  totalturnaround= totalturnaround + p[i]->turnaround;
		}
		avgWaiting = totalWaiting *1.0 / max;
		double avgTT=totalturnaround*1.0/max;
		printf("%.2f\n",avgWaiting);
		printf("%.2f",avgTT);
		
	
 
} 
