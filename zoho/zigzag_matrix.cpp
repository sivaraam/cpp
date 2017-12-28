#include <iostream>

using std::cout;
using std::cin;

int find_num(int diagonal, int order) {
//	int num=0;
	if (diagonal<=order)
		return diagonal;
	else {
		return order-(diagonal-order);
	}
}

// cout<<"DEBUG: ";
int generate_diagonal_indices(int diagonal, int *row_indices, int *col_indices, int order) {
	int num_elements = find_num(diagonal, order);
//	cout<<"DEBUG: "<<num_elements<<'\n';
	int sum=diagonal-1, j=0;
	bool went=0;

	for (int i=0, iter=0; iter<num_elements; iter++) {
		if (diagonal<=order) {
			row_indices[iter]=i;
			col_indices[iter]=sum-i;
		}
		else {
			if (!went) {
				j=sum-i;
				while (j>=order)
					j--;
				went=1;
			}
			col_indices[iter]=j;
			row_indices[iter]=sum-j;
			j--;
		}
		i++;
	}
	return num_elements;
}

int main() {
	int order=0;
	int mat[100][100];

	cout<<"Enter the order of square matrix: ";
	cin>>order;

	cout<<"Enter the matrix:\n";
	for (int i=0; i<order; i++) {
		for (int j=0; j<order; j++)
			cin>>mat[i][j];
	}

	int diagonals=2*order-1;
	int row_indices[order];
	int col_indices[order];

	for (int i=0; i<diagonals; i++) {
		int diagonal_indices = generate_diagonal_indices(i+1, row_indices, col_indices, order);
		if (i%2==0) {
			for (int j=diagonal_indices-1; j>=0; j--) {
//				cout<<"DEBUG: "<<row_indices[j]<<' '<<col_indices[j]<<'\n';
				cout<<mat[row_indices[j]][col_indices[j]]<<' ';
			}
		}
		else {
			for (int j=0; j<diagonal_indices; j++) {
//				cout<<"DEBUG: "<<row_indices[j]<<' '<<col_indices[j]<<'\n';
				cout<<mat[row_indices[j]][col_indices[j]]<<' ';
			}
		}
	}

}
//
//#include <cstring>
//#include <algorithm>
//#include <string>
//#include <cmath>
//
//using std::cout;
//using std::cin;
//using std::vector;
//using std::string;

