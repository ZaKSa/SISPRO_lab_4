#include <iostream>

using namespace std;

//8. Найти разность суммы положительных и суммы отрицательных элементов
// массива A = { a[i] }.

int main()
{
	int n, res, ofs = 0;
	cout << "Enter size: ";
	cin >> n;
	int* mas = new int[n];

	cout << "Enter mass\n";
	for (int i = 0; i < n; i++)
		cin >> mas[i];

	__asm {
		xor esi, esi; подготовка регистр индекса в массиве
		xor edi, edi; счётчик количества элементов
		mov ebx, mas; ebx указывает на начало массива
		mov ecx, n; счётчик цикла по всем элементам массива
		jecxz END

		begin_loop:
					mov eax, [ebx + esi * 4];
					mov edx, 0
					cmp eax, edx; сравнение a[i] и 0
						
						jg l_bigger; если a > b
						jl l_smaller; если a < b

						l_bigger: 
					add edi, eax
						jo errorOF
						jmp end_loop

						l_smaller:
					sub edi, eax
						jo errorOF
						jmp end_loop

		end_loop:
					inc esi
						loop begin_loop
						jmp END

		errorOF:
						mov ofs, 1
						jmp END

		END:
					mov res, edi
	}
	if (ofs == 1)
		cout << endl << "Out of size\n" << endl;
	else
	cout << "Res: " << res;

	delete[] mas;
}