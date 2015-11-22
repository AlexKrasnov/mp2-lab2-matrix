#include "utmatrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) //начальный
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) //начальный
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) //начальный
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) //начальный
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = 1;
		}
		TMatrix<int> m2(m1);
		EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = i;
		}
		TMatrix<int> m2(m1);
		EXPECT_NE(&m1[m1.GetStartIndex()], &m2[m2.GetStartIndex()]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> m(5); 
	EXPECT_EQ(m.GetSize(), 5); 
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	for (int i = 0; i < m.GetSize(); i++)
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = 1;
		}
		EXPECT_EQ(m[0][0], 1); 
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][-1]=0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][10]=0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TVector<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
		}
		ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(10), m2(11);
	int len = m1.GetSize();
	m1=m2;
	EXPECT_NE(len, m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(5),m2(6);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = 0;
		}
		for (int i = 0; i < m2.GetSize(); i++)
			for (int j = i; j < m2.GetSize(); j++)
			{
				m2[i][j] = 1;
			}
			ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(5);
	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = i; j < m1.GetSize(); j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
		m1[4][4] = 0;
		m2[4][4] = 0;
		TMatrix<int> m3(m2);
		EXPECT_EQ(true, m1==m2);
		m2=m1;
		EXPECT_EQ(true, m3==m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m[i][j]=1;
	EXPECT_EQ(true,m==m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(6);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m1[i][j] = 1;
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
			m2[i][j] = 1;
	EXPECT_EQ(true, m1!=m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    for (int i = 0; i < a.GetSize(); i++)
        for (int j = i; j < a.GetSize(); j++)
        {
            a[i][j] = 0;
            b[i][j] = 1;
        }
    ASSERT_NO_THROW(a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(10),b(11);
	for (int i=0;i<a.GetSize();i++)
		for (int j=i;j<a.GetSize();j++)
			a[i][j]=0;
	for (int i=0;i<b.GetSize();i++)
		for (int j=i;j<b.GetSize();j++)
			b[i][j]=1;
	ASSERT_ANY_THROW(a+b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    for (int i = 0; i < a.GetSize(); i++)
        for (int j = i; j < a.GetSize(); j++)
        {
            a[i][j] = 0;
            b[i][j] = 1;
        }
    ASSERT_NO_THROW(a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(10),b(11);
	for (int i=0;i<a.GetSize();i++)
		for (int j=i;j<a.GetSize();j++)
			a[i][j]=0;
	for (int i=0;i<b.GetSize();i++)
		for (int j=i;j<b.GetSize();j++)
			b[i][j]=1;
	ASSERT_ANY_THROW(a-b);
}



