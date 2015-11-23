#include "utmatrix.h"

#include <gtest.h>

TEST( TVector, can_create_vector_with_positive_length) //начальный
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) //начальный
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length) //начальный
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex) //начальный
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector) //начальный
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) 
{
	TVector<int> vector(10);
	for (int i = 0; i < vector.GetSize(); i++)
		vector[i] = i;
	TVector<int> copy_vector(vector);
	EXPECT_EQ(copy_vector, vector);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> vector(10);
	for (int i = 0; i < vector.GetSize(); i++)
		vector[i] = i;
	TVector<int> copy_vector(vector);
	EXPECT_NE(&vector[vector.GetStartIndex()], &copy_vector[copy_vector.GetStartIndex()]);
}

TEST(TVector, can_get_size) //начальный
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index) //начальный
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) //начальный
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> a(10);
	ASSERT_ANY_THROW(a[-5] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> a(10);
	ASSERT_ANY_THROW(a[15] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(10);
	for (int i = 0; i < 10; i++)
		v1[i] = i;
	TVector<int> v2(10);
	for (int j = 0; j < 10; j++)
		v2[j] = j;
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> vector1(10), vector2(15);
	int len = vector1.GetSize();
	vector1=vector2;
	EXPECT_NE(len, vector1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> vector1(10), vector2(15);
	for (int i=0;i<10;i++)
		vector1[i]=0;
	for (int i=0;i<15;i++)
		vector2[i]=0;
	ASSERT_NO_THROW(vector1=vector2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i*i;
		v2[i] = i*i;
	}
	v1[4] = 1;
	v2[4] = 1;
	EXPECT_EQ(true, v1==v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(10);
	for (int i=0;i<v.GetSize();i++)
		v[i]=0;
	EXPECT_EQ(true,v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(10),v2(11);
	for (int i=0;i<10;i++)
	{
		v1[i]=0;
		v2[i]=0;
	}
	v2[10]=0;
	EXPECT_EQ(true,v1!=v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> a(10);
	for (int i=0;i<10;i++)
		a[i]=0;
	TVector<int> b(a);
	for (int i=0;i<10;i++)
		a[i]+=5;
	ASSERT_NO_THROW(b+5);
	EXPECT_EQ(a,b+5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(10);
	for (int i=0;i<10;i++)
		a[i]=0;
	TVector<int> b(a);
	for (int i=0;i<10;i++)
		a[i]-=5;
	ASSERT_NO_THROW(b-5);
	EXPECT_EQ(a,b-5);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(10);
	for (int i=0;i<10;i++)
		a[i]=0;
	TVector<int> b(a);
	for (int i=0;i<10;i++)
		a[i]*=5;
	ASSERT_NO_THROW(b*5);
	EXPECT_EQ(a,b*5);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(10);
	for (int i=0;i<a.GetSize();i++)
	{
		a[i]=i;
	}
	TVector<int> b(a);
	TVector<int> c(b);
	for (int i=0;i<a.GetSize();i++)
	{
		c[i]+=a[i];
	}
	ASSERT_NO_THROW(a+b);
	EXPECT_EQ(true,c==a+b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(10),b(11);
	for (int i=0;i<10;i++)
	{
		a[i]=0;
		b[i]=1;
	}
	b[10]=1;
	ASSERT_ANY_THROW(a+b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(10);
	for (int i=0;i<a.GetSize();i++)
	{
		a[i]=i;
	}
	TVector<int> b(a);
	TVector<int> c(b);
	for (int i=0;i<a.GetSize();i++)
	{
		c[i]-=a[i];
	}
	ASSERT_NO_THROW(a-b);
	EXPECT_EQ(true,c==a-b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> a(10),b(11);
	for (int i=0;i<10;i++)
	{
		a[i]=0;
		b[i]=1;
	}
	b[10]=1;
	ASSERT_ANY_THROW(a-b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(3);
	for (int i=0;i<a.GetSize();i++)
	{
		a[i]=1;
	}
	TVector<int> b(a);
	TVector<int> c(b);
	for (int i=0;i<a.GetSize();i++)
	{
		b[i]*=2;
	}
	ASSERT_NO_THROW(a*b);
	EXPECT_EQ(true,6==a*b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(10),b(11);
	for (int i=0;i<10;i++)
	{
		a[i]=0;
		b[i]=1;
	}
	b[10]=1; 
	ASSERT_ANY_THROW(a*b);
}

// My tests:

TEST(TVector, throws_when_create_vector_with_wrong_startindex) //собственный
{
	ASSERT_ANY_THROW(TVector<int> v(3, 3)); //StartIndex = Size
	ASSERT_ANY_THROW(TVector<int> v(3, 5)); //StartIndex > Size
}


TEST(TVector, can_set_and_get_element_improved) // собственный
{
	TVector<int> w(5);
	ASSERT_NO_THROW(w[0]);
    ASSERT_NO_THROW(w[0]=5);
	w[0] = 5;
	EXPECT_EQ(5, w[0]);
}

TEST(TVector, throws_when_set_element_with_wrong_index) // собственный
{
	TVector<int> a(10, 5);
	ASSERT_ANY_THROW(a[3] = 1); //Size < StartIndex
}

TEST(TVector, compare_no_equal_vectors_return_false) // собственный
{
	TVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = i*i;
		v2[i] = i*i;
	}
	v1[4] = 1;
	v2[4] = 1;
	EXPECT_EQ(false, v1!=v2);
}