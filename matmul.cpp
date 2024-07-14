#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void matmul(float *A, float *B, float *C, int N, int M, int K) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      float sum = 0;
      for (int k = 0; k < M; k++) {
        sum += A[i * M + k] * B[k * K + j];
      }
      C[i * K + j] = sum;
    }
  }
}



void matmul_byhand(float* input, float* weight, float* out, int N, int M, int K) {
	for(int input_row_idx=0; input_row_idx < N; input_row_idx++) {
		for(int output_col_idx =0 ; output_col_idx < K; output_col_idx++) {
      float sum = 0.0;
      for(int m_idx =0; m_idx < M; m_idx++) {
        int input_idx = input_row_idx * M + m_idx;
        int weight_idx = m_idx *  K  + output_col_idx;
        sum += input[input_idx] * weight[weight_idx];
      }

      int out_idx = input_row_idx * K + output_col_idx;
      out[out_idx] = sum;
    }
	}
}


int main() {
  int N = 3;
  int M = 3;
  int K = 4;
  float A[N * M];
  float B[M * K];
  float C[N * K];

  for (int i = 0; i < N * M; i++) {
    A[i] = i;
  }
  for (int i = 0; i < M * K; i++) {
    B[i] = i;
  }

  matmul(A, B, C, N, M, K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      printf("%f ", C[i * K + j]);
    }
    printf("\n");
  }

  matmul_byhand(A, B, C, N, M, K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      printf("%f ", C[i * K + j]);
    }
    printf("\n");
  }

  return 0;

}
