/*
#include <iostream>
#include <iomanip> // setw(n) : �� ������  nĭ�� �Ҵ�, ������ ����
#include <fstream>//ofstream ifstream fstream
using namespace std;
*/



/*
//void swap(int a, int b) : pass by value : ���翡 ���� �� ����
//void swap(int& a, int& b) : pass by reference  ������ ���� �� ����

void swap(int& a, int& b) {
	int alpha;
	alpha = a;
	a = b;
	b = alpha;
}

int main() {
	int x = 10, y = 1000;
	cout << x << '\t' << y << endl;
	swap(x, y);
	cout << x << '\t' << y << endl;

	return 0;
}

*/

/*

int main() {
	bool a = true;
	// ���� ���� 1�̶�� ���� ���´�
	bool b = (10 >= 5);
	// ������ ���̶�� 1�� ��ȯ�Ѵ�(������ 0�� ��ȯ�Ѵ�.
	bool c = 1000;
	//bool ������ 0�� �ƴϸ� ���̶�� �ν��Ѵ�.

	cout << a << endl << b << endl << c << endl;
	return 0;
}

*/

/*
int main() {
	int dividend, divisor;
	cout << "Enter dividend : ";
	cin >> dividend;
	cout << "Enter divisor : ";
	cin >> divisor;

	if ( divisor == 0)
		cout << "You enter the divisor 0. it can't do it" << endl;

	else 
		cout << "result : " << dividend / divisor << endl;
	

	return 0;
}

*/

/*
int main() {
	int sum = 0;
	int i = 1;
	int n;
	cin >> n;
	//cout.immbue
	while( i<=n){
		if ( i%2 != 0) 
			sum += i;
		i++;
		cout << i << '\t' << sum << endl;
	}
	cout << sum << endl;

	return 0;
}

*/

/*
void makeRowCal(int row, int col) {
	cout << row << " * " << col << "Matrix is here" << endl;
	for (int a = 1; a <= col; a++) {
		for (int b = 1; b <= row; b++) {
			int val = a * b;
			cout << setw(4) << val;
		}
		cout << endl;
	}
}

int main() {
	int row = 1, col = 1;

	cout << "Enter the row :";
	cin >> row;
	cout << "Enter the col :";
	cin >> col;

	makeRowCal(row, col);
	*/
/*
	while (row <= 5) {
		while (col <= 5) {
			int val = row * col;
			cout << setw(4) << val;
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
	

	return 0;
}

*/

/*
int main() {
	int sum = 0;
	int input;
	while (true) {
		cout << "Enter a number : ";
		cin >> input;
		if (input < 0)
			continue; // �Ʒ��κ� �������� �ʰ� �ݺ��� ó������ ���ư�
			//break; while���� ������ ���߰� Ż���Ѵ�.
		}
	return 0;
}
*/

//do-while��
/*
int main() {
	int input;

	do {
		cout << "Enter a number [0.10]: ";
		cin >> input;
	} while (!( input >= 0 && input <=10));

	cout << "Output: " << input << endl;

	return 0;
}
*/

/*
int main() {
	int sum = 0;

	// for(�ʱ�ȭ;�ݺ�����;������Ʈ{
	//main_body
	//}

	for (int i = 0; i <= 100; i++) {
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
*/


/*
int main() {

	int size;
	cout << "Enter the size : ";
	cin >> size;
	
	for (int row = 1; row <= size; row++) {
		for (int col = 1; col <= size; col++){
//			int val = row * col;
//			int val = (row > col ? row : col);
			//���ǽ� ( row�� col���� ũ�� row�� ����, �����̸� col�� ����)
			int val = 0;
			if (row == col)
				val = 1;
			cout << setw(4) << val;
		}
	cout << endl;

	}

	return 0;
}
*/

/*
int main() {
	char input;
	cin >> input;

	switch (input) {
	case 'p':
		cout << "Pause" << endl;
		cout << "Fuck" << endl;
		break;
	case'q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
	}

	return 0;
}

*/


/*
int main() {
	char ch;
	ofstream fout;
	fout.open("char.txt");
	while (true) {
		cin >> ch;
		if (ch == 'q')
			break;
		fout.put(ch);
	}

	fout.close();

	ifstream fin;
	fin.open("char.txttt");

	if (!fin) {
		cout << "ERROR" << endl;
		exit(100);
	}

	while(true) {
		fin.get(ch);
		if (!fin)//������ ������ �� ������ fin == false(fin.eof())
			break;
		cout << ch << endl;
	}

	fin.close();

	return 0;
}
*/


/*
int main() {
	double a = 12.345;

	cout << a << endl;
//	cout.width(15); // setw(15)
	cout.precision(4);
	cout.fill('-');
	cout << a << endl;

	char ch;
	cin.unsetf(ios::skipws);
	//C++�� ���鹮�ڸ� ���� �����Ѵ�. ���� �Լ� ����ϸ� �����̽��� �Է����� ����Ѵ�.
	cin.setf(ios::skipws);
	cin >> ch;
	cout << "( " << ch << " )" << endl;

	return 0;
}
*/

/*
bool readStu(ifstream& fin, int& id, int& a, int& b, int& c) {
	fin >> id >> a >> b >> c;
	if (!fin)
		return false;
	else
		return true;
}

void calcGrade(int score1, int score2, int score3, int& ave, char& grade) {
	ave = ( score1 + score2 + score3 ) / 3;
	if (ave >= 90)
		grade = 'A';
	else if (ave >= 80)
		grade = 'B';
	else if (ave >= 70)
		grade = 'C';
	else if (ave >= 60)
		grade = 'D';
	else
		grade = 'F';
}

void writeStu(ofstream& fout, int id, int ave, char grade) {
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(3) << ave;
	fout << setw(2)<< grade << endl;

}

int main() {
	// 1. �л� ������ �д´�. ch7STUFL.DAT (ID, scroe1, 2, 3)
	// 2. �������� ��հ��� ���Ѵ�. grade�� �����Ѵ�.
	// 3. ���Ͽ� ID, ave,, grade�� �Է��Ѵ�.

	ifstream fin;
	fin.open("ch7STUFL.DAT");
	ofstream fout;
	fout.open("Grade.txt");
	int id, score1, score2, score3, ave;
	char grade;

	if (!fin||!fout) {
		exit(100);
	}



	while (readStu(fin, id, score1, score2, score3)) {
		calcGrade(score1, score2, score3, ave, grade);
		writeStu(fout, id, ave, grade);
	}

	cout << "End Grading" << endl;
	
	fin.close();
	fout.close();

	return 0;
}

*/


#include <iostream>
#include <vector>


bool is_prime(int num) {
	if (num % 2 == 1)
		return true;
	else
		return false;
}

std::vector<int> primes(int low, int high) {
	std::vector<int> primevec;

	for (int i = low; i <= high; i++) {
		if (is_prime(i))
			primevec.push_back(i);
	}

	return primevec;
}

void printVecter(std::vector<int>& v) {
	int size = v.size();
	for (int i = 0; i < size; i++)
		std::cout << v[i] << "     ";
}

int main() {
	int low, high;
	std::cin >> low >> high;
	std::vector<int> vec = primes(low, high);
	printVecter(vec);
	int a = 4;
	return 0;
}