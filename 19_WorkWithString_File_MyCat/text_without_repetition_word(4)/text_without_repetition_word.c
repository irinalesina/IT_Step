#include "text_without_repetition_word.h"

char* TextWithoutRepeatitionWord(char *str)
{
    static char result[N] = {0};
    char word[N] = {0}, pred_result[N][N] = {0};//матрица для улучшения поиска слов
    char *space_pointer, *prev_pointer = str;
    int exit_ = 1, result_word_count = 0;
    while(exit_)
    {
        space_pointer = strchr(prev_pointer, ' ');
        if (space_pointer == NULL)
        {
            space_pointer = strchr(prev_pointer, '\0');
            exit_ = 0;
        }

        memcpy(word, prev_pointer, space_pointer - prev_pointer + 1);//копирование слова

        if(*prev_pointer == *(space_pointer - 1))//проверка 1 и последней буквы слова
        {
            int exist = 0, i;//exist-для проверки на совпадение слов
            for(i = 0; i < result_word_count; i++)//проверка совпадения слов
            {
                if(strcmp(pred_result[i], word) == NULL)//одинаковых слов нету
                {
                    exist = 1;
                    break;
                }
            }
            if(!exist)//если одинаковых слов нету записать слово
            {
                strcat(pred_result[result_word_count++], word);
            }

        }

        prev_pointer = space_pointer + 1;
        memset(word, 0, sizeof(word));//очистка вспомогательного массива для запоминания слова
    }
    int i;
    for(i = 0; i < result_word_count; i++)//записывание результата
    {
        strcat(result, pred_result[i]);
    }
    return result;
}
