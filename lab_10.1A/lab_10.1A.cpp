#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "����������� ",
                            "��������������", "����'����� �����",
                            "����'������ ��������", "��������� ������������" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
};

void Create(Students* S, const int N);
void count_math_grades(Students* S, int N, int& count_5, int& count_4, int& count_3);
void Print_students_with_5_in_physics_and_math(Students* S, const int N);
void Print(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    int count_5 = 0;
    int count_4 = 0;
    int count_3 = 0;
   count_math_grades(S, N, count_5, count_4, count_3);

    cout << "ʳ������ �������� � ������� '5' � ����������: " << count_5 << endl;
    cout << "ʳ������ �������� � ������� '4' � ����������: " << count_4 << endl;
    cout << "ʳ������ �������� � ������� '3' � ����������: " << count_3 << endl;

    cout << "��������, �� �������� '5' � ������ �� ����������:" << endl;
    Print_students_with_5_in_physics_and_math(S, N);

    delete[] S;
    return 0;
}

void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������(0 - �����������, 1 - ��������������, 2 - ����'����� �����," << endl;
        cout << "3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics; cout << endl;
        cout << "������ � ����������: "; cin >> S[i].grade_math; cout << endl;
        cout << endl;
    }
}

void count_math_grades(Students* S, int N, int& count_5, int& count_4, int& count_3)
{
    count_5= 0;
    count_4 = 0;
    count_3 = 0;

    for (int i = 0; i < N; i++) {
        if (S[i].grade_math == 5) {
            count_5++;
        }
        if (S[i].grade_math == 4) {
            count_4++;
        }
        if (S[i].grade_math == 3) {
            count_3++;
        }
    }
}

void Print(Students* S, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |     ������������     |  Գ����  |  ����������  |  �����������  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}

void Print_students_with_5_in_physics_and_math(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (S[i].grade_physics == 5 && S[i].grade_math == 5)
        {
            cout << S[i].surname << endl;
        }
    }
}
