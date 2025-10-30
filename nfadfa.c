#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define MAX_DFA 100

int nfa[MAX][MAX];
int nfa_states, symbols;
int final_states[MAX], final_count;
int dfa_states[MAX_DFA][MAX];
int dfa_trans[MAX_DFA][MAX];
int dfa_final[MAX_DFA];
int dfa_count = 0;

int is_final_state(int state[])
{
    for (int i = 0; i < final_count; i++)
        if (state[final_states[i]])
            return 1;
    return 0;
}

int is_same_state(int s1[], int s2[])
{
    for (int i = 0; i < nfa_states; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int find_state_index(int state[][MAX], int state_count, int current[])
{
    for (int i = 0; i < state_count; i++)
    {
        if (is_same_state(state[i], current))
            return i;
    }
    return -1;
}

void print_state(int s[])
{
    printf("{");
    for (int i = 0; i < nfa_states; i++)
    {
        if (s[i])
            printf("q%d,", i);
    }
    printf("}\t");
}

int main()
{
    printf("Enter number of NFA states: ");
    scanf("%d", &nfa_states);
    printf("Enter number of input symbols: ");
    scanf("%d", &symbols);

    printf("Enter NFA transition table:\n");
    for (int i = 0; i < nfa_states; i++)
    {
        for (int j = 0; j < symbols; j++)
        {
            int count;
            printf("Enter number of transitions from q%d on symbol %d: ", i, j);
            scanf("%d", &count);
            if (count != 0)
                printf("Enter destination states: ");
            for (int k = 0; k < count; k++)
            {
                int to;
                scanf("%d", &to);
                nfa[i * symbols + j][k] = to;
            }
            nfa[i * symbols + j][count] = -1;
        }
    }

    printf("Enter number of final states in NFA: ");
    scanf("%d", &final_count);
    printf("Enter final states: ");
    for (int i = 0; i < final_count; i++)
        scanf("%d", &final_states[i]);

    int queue[MAX_DFA], front = 0, rear = 0;
    int start[MAX] = {0};
    start[0] = 1;
    memcpy(dfa_states[dfa_count], start, sizeof(start));
    queue[rear++] = dfa_count;
    dfa_count++;

    while (front < rear)
    {
        int current_index = queue[front++];
        int *current = dfa_states[current_index];
        for (int sym = 0; sym < symbols; sym++)
        {
            int next[MAX] = {0};
            for (int i = 0; i < nfa_states; i++)
            {
                if (current[i])
                {
                    for (int k = 0; nfa[i * symbols + sym][k] != -1; k++)
                    {
                        int to = nfa[i * symbols + sym][k];
                        next[to] = 1;
                    }
                }
            }

            int found = find_state_index(dfa_states, dfa_count, next);
            if (found == -1)
            {
                memcpy(dfa_states[dfa_count], next, sizeof(next));
                dfa_trans[current_index][sym] = dfa_count;
                queue[rear++] = dfa_count;
                dfa_count++;
            }
            else
            {
                dfa_trans[current_index][sym] = found;
            }
        }
    }

    for (int i = 0; i < dfa_count; i++)
        dfa_final[i] = is_final_state(dfa_states[i]);

    printf("\nDFA States and Transitions:\n");
    printf("States\t\t");
    for (int sym = 0; sym < symbols; sym++)
    {
        printf("\t%d", sym);
    }
    printf("\n-----------------------------------\n");

    for (int i = 0; i < dfa_count; i++)
    {
        printf("%d->", i);
        print_state(dfa_states[i]);
        for (int sym = 0; sym < symbols; sym++)
        {
            printf("\t%d", dfa_trans[i][sym]);
        }
        if (dfa_final[i])
            printf(" [Final]");
        printf("\n");
    }
    return 0;
}

/*
PS D:\MITS\S7\CD Lab> .\a.exe
Enter number of NFA states: 3
Enter number of input symbols: 2
Enter NFA transition table:
Enter number of transitions from q0 on symbol 0: 2
Enter destination states: 0 1
Enter number of transitions from q0 on symbol 1: 1
Enter destination states: 0
Enter number of transitions from q1 on symbol 0: 1
Enter destination states: 2
Enter number of transitions from q1 on symbol 1: 0
Enter number of transitions from q2 on symbol 0: 0
Enter number of transitions from q2 on symbol 1: 1
Enter destination states: 2
Enter number of final states in NFA: 1
Enter final states: 2

DFA States and Transitions:
States                  0       1
-----------------------------------
0->{q0,}                1       0
1->{q0,q1,}             2       0
2->{q0,q1,q2,}          2       3 [Final]
3->{q0,q2,}             1       3 [Final]
*/
