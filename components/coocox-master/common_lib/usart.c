#include "usart.h"

char received_string[received_string_length];
unsigned int received_count = 0; // count of charrs

void usart1_print(const char* c) {
    u8 a = 0;
    while (c[a]) {
        PrintChar(c[a++]);
    }
}

void usart2_print(char* c) {
    u8 a = 0;
    while (c[a]) {
        PrintCharPc(c[a++]);
    }
}

void USART1_Init(uint32_t baud)
{
    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* Enable UART clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    // Use PA9 and PA10
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // USART1
    USART_InitStructure.USART_BaudRate = baud;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;

    USART_Init(USART1, &USART_InitStructure);

    // Enable usart
    USART_Cmd(USART1, ENABLE);

}

void USART2_Init(uint32_t baud)
{
    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* Enable UART clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    // Use PA2 and PA3
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // USART2
    USART_InitStructure.USART_BaudRate = baud;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;

    USART_Init(USART2, &USART_InitStructure);

    // Enable usart
    USART_Cmd(USART2, ENABLE);

}

void usart_string_append(char c) {
    received_string[received_count++] = c;
}

char usart_get_previous_char() {
    if (received_count > 1) {
        return received_string[received_count - 2];
    }
    return '\0';
}

void usart_clear_string() {
    memset(received_string, 0, received_string_length);
    received_count = 0;
}

char* usart_get_string() {
    return received_string;
}
u8 usart_get_string_length() {
    return received_count;
}

//function from kbiva
int GetChar (USART_TypeDef* USARTx) {
	
  while (!(USARTx->SR & USART_FLAG_RXNE)){};
  return ((int)(USARTx->DR & 0xFF));

}

int SendChar (USART_TypeDef* USARTx, int ch) {
	
  while (!(USARTx->SR & USART_FLAG_TXE)){};
  USARTx->DR = (ch & 0xFF);
  return (ch);
}

