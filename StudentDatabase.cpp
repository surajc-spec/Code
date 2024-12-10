#include <iostream>
#include <string.h>
using namespace std;

struct Student
{

    int rollno;
    char name[30];
    float sgpa;
};
// display function

void display(struct Student s[30], int n)
{
    cout << "======================================================";
    cout << "\nrollno \tName   \tSGPA";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << s[i].rollno << "\t" << s[i].name << "\t" << s[i].sgpa;
    }
}

// bubble sort function

void bubblesort(struct Student s[30], int n)
{
    int temp;
    float sg;
    char na[30];
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {

            if (s[j].rollno > s[j + 1].rollno)
            {
                temp = s[j].rollno;
                s[j].rollno = s[j + 1].rollno;
                s[j + 1].rollno = temp;

                sg = s[j].sgpa;
                s[j].sgpa = s[j + 1].sgpa;
                s[j + 1].sgpa = sg;

                strcpy(na, s[j].name);
                strcpy(s[j].name, s[j + 1].name);
                strcpy(s[j + 1].name, na);
            }
        }
    }
    cout << "\nData sorted according to rollno : \n";
    display(s, n);
}

// insertion sort
void insertionsort(struct Student s[30], int n)
{
    char na[30];
    int r;
    float sg;
    for (int i = 1; i < n; i++)
    {
        strcpy(na, s[i].name);
        r = s[i].rollno;
        sg = s[i].sgpa;
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, na) > 0)
        {
            strcpy(s[j + 1].name, s[j].name);
            s[j + 1].rollno = s[j].rollno;
            s[j + 1].sgpa = s[j].sgpa;

            j--;
        }
        strcpy(s[j + 1].name, na);
        s[j + 1].rollno = r;
        s[j + 1].sgpa = sg;
    }
    cout << "\nData sorted according to names : \n";
    display(s, n);
}

// linear search function

void linearSearch(struct Student s[30], int n, float data)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == data)
        {
            cout << "\n"
                 << s[i].rollno << "\t" << s[i].name << "\t" << s[i].sgpa;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Data is not found in data base  ! ";
    }
}

// binary search function
void binarySeaerch(struct Student s[30], int n, char data[30])
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int flag = 0;

    while (start <= end)
    {
        if (strcmp(data, s[mid].name) == 0)
        {
            flag = 1;
            break;
        }
        else if (strcmp(data, s[mid].name) < 0)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (flag == 1)
    {
        cout << "\n rollno : " << s[mid].rollno;
        cout << "\n name : " << s[mid].name;
        cout << "\n sgpa : " << s[mid].sgpa;
        cout << endl;
    }
    else
    {
        cout << "\n Data not found in data base \n ";
    }
}

// Partion function

int partition(struct Student s[30], int lb, int ub)
{
    int start, end;
    float pivot = s[lb].sgpa;
    float sg;
    int r;
    char na[30];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (s[start].sgpa <= pivot)
        {
            start++;
        }
        while (s[end].sgpa > pivot)
        {
            end--;
        }
        if (start < end)
        {
            sg = s[start].sgpa;
            s[start].sgpa = s[end].sgpa;
            s[end].sgpa = sg;
            r = s[start].rollno;
            s[start].rollno = s[end].rollno;

            s[end].rollno = r;
            strcpy(na, s[start].name);
            strcpy(s[start].name, s[end].name);
            strcpy(s[end].name, na);
        }
    }
    sg = s[lb].sgpa;
    s[lb].sgpa = s[end].sgpa;
    s[end].sgpa = sg;
    r = s[lb].rollno;
    s[lb].rollno = s[end].rollno;
    s[end].rollno = r;
    strcpy(na, s[lb].name);
    strcpy(s[lb].name, s[end].name);
    strcpy(s[end].name, na);
    return end;
}

// quicksort function

void quickSort(struct Student s[], int n, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(s, lb, ub);
        quickSort(s, n, lb, loc - 1);
        quickSort(s, n, loc + 1, ub);
    }
}

int main()
{

    struct Student s[30];
    int i, n, ch;
    char na[30];
    float sg;

    cout << "enter no of students : ";
    cin >> n;
    cout << "enter student information:\n";

    for (i = 0; i < n; i++)
    {

        cout << "enter roll,name,sgpa : \n";
        cin >> s[i].rollno >> s[i].name >> s[i].sgpa;
    }

    display(s, n);

    do
    {
        cout << "\n======================================================";
        cout << " \n 1.bubble sort";
        cout << "\n 2.insertion sort";
        cout << "\n 3.linear search";
        cout << "\n 4.binary search";
        cout << "\n 5.quick sort";
        cout << "\n 6.exit\n";
        cout << "======================================================\n";
        cout << "\n enter the choice ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            bubblesort(s, n);
            break;

        case 2:
            insertionsort(s, n);
            break;

        case 3:
            cout << "\nenter sgps to search : ";
            cin >> sg;
            linearSearch(s, n, sg);
            break;

        case 4:
            cout << "enter name to search : ";
            cin >> na;
            binarySeaerch(s, n, na);
            break;

        case 5:
            quickSort(s, n, 0, n - 1);
            cout << "\n Top ten toppers are:\n";
            cout << "\nrollno\tName\tSGPA";

            for (i = n - 1; i >= 0; i--)
            {
                int count = 0;
                count++;
                if (count > 10)
                {
                    break;
                }
                cout << "\n"
                     << s[i].rollno << "\t" << s[i].name << "\t" << s[i].sgpa;
            }
            break;

            cout << "======================================================\n";

        case 6:
            break;
        }
    } while (ch != 6);
    return 0;
}




