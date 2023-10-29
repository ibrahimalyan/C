//id:322675356
#include "StudentList.h"
#include <stdio.h>
#include <stdlib.h>

void printStudentNode(StudentNode* const std_node){
    printf("Student:{ ID: %d, Grade1:%d, Grade2:%d }\n", std_node->st->id, std_node->st->grade1, std_node->st->grade2);

}

void printStudentList(StudentList* const first_node){

    StudentNode * current = first_node->head->next;
    while (current != NULL)
    {
        printStudentNode(current);
        current = current -> next;

    }

}

int main(int argc, char const *argv[])
{

    FILE *fptr = fopen("StudentsGrades.txt", "r");

    StudentNode * First_Node = (StudentNode *)malloc(sizeof(StudentNode));

    int id, sunday, monday;

    int number_of_items = fscanf(fptr, "%d %d %d\n", &id, &sunday, &monday);

    // Student * first = (Student *)malloc(sizeof(Student));

    // first->id = id;
    // first->grade1 = monday;
    // first->grade2 = sunday;

    // First_Node->st = first;
    First_Node->next = NULL;

    StudentNode * current = First_Node;

    while (number_of_items == 3)
    {
        printf("ID: %d, Sun:%d, Mon:%d\n", id, sunday, monday);

        Student *new_s = (Student *)malloc(sizeof(Student));

        new_s->id = id;
        new_s->grade1 = monday;
        new_s->grade2 = sunday;

        StudentNode *new_node = (StudentNode *)malloc(sizeof(StudentNode));

        new_node->st = new_s;
        new_node->next = NULL;

        current->next = new_node;

        current = new_node;

        number_of_items = fscanf(fptr, "%d %d %d\n", &id, &sunday, &monday);
    }

    fclose(fptr);

    // ////////////

    int count = 0,
            count_one_exam = 0,
            count_no_exam = 0,
            count_of_fails_A = 0,
            count_of_fails_B = 0,
            count_attended_A =0,
            count_attended_B =0,
            sum_of_A_marks = 0,
            sum_of_B_marks = 0,
            id_of_max=First_Node->next->st->id,
            max_grade=First_Node->next->st->grade1,
            id_of_min=First_Node->next->st->id,
            min_grade=First_Node->next->st->grade1;

    current = First_Node->next;
    while (current != NULL)
    {
        count++;

        if ((current->st->grade1 != -1 && current->st->grade2 == -1) || (current->st->grade2 != -1 && current->st->grade1 == -1))
        {
            count_one_exam++;
        }
        else if (current->st->grade1 == -1 && current->st->grade2 == -1)
        {
            count_no_exam++;
        }

        if (current->st->grade1 < 60)
        {
            count_of_fails_A++;
        }

        if (current->st->grade2 < 60)
        {
            count_of_fails_B++;
        }

        if ( current->st->grade1 != -1 ){
            count_attended_A ++;
            sum_of_A_marks += current->st->grade1;

            if ( current->st-> grade1 > max_grade ){
                max_grade = current->st-> grade1;
                id_of_max = current->st-> id;
            }

            if ( current->st-> grade1 < min_grade ){
                min_grade = current->st-> grade1;
                id_of_min = current->st-> id;
            }
        }

        if ( current->st->grade2 != -1 ){
            count_attended_B ++;
            sum_of_B_marks += current->st->grade2;

            if ( current->st-> grade2 > max_grade ){
                max_grade = current->st-> grade2;
                id_of_max = current->st-> id;
            }
            if ( current->st-> grade2 < min_grade ){
                min_grade = current->st-> grade2;
                id_of_min = current->st-> id;
            }


        }

        StudentNode * next = current->next;

        free(current->st);
        free(current);

        current = next;

    }

    FILE * report_fptr = fopen("Report.txt", "w");

    fprintf(report_fptr, "Count of students is %d\n", count);
    fprintf(report_fptr, "Count of students who attended one exam is %d\n", count_one_exam);
    fprintf(report_fptr, "Count of students who did not attend any exam is %d\n", count_no_exam);

    fprintf(report_fptr, "Percentage of failure in session A is %f\n", (((float)count_of_fails_A) / count));
    fprintf(report_fptr, "Percentage of failure in session B is %f\n", (((float)count_of_fails_B) / count));

    fprintf(report_fptr, "Average of grades in session A is %f\n", (((float) sum_of_A_marks) / count_attended_A));
    fprintf(report_fptr, "Average of grades in session B is %f\n", (((float) sum_of_B_marks) / count_attended_B));

    fprintf(report_fptr, "Id of Student with max grade is %d\n", id_of_max);
    fprintf(report_fptr, "Id of Student with min grade is %d\n", id_of_min);

    fclose(report_fptr);

    return 0;
}

