/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: console Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_badSink(wchar_t * dataArray[]);

void CWE606_Unchecked_Loop_Condition__wchar_t_console_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)//SLIVER_SOURCE
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    /* put data in array */
    dataArray[2] = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_badSink(dataArray);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_goodG2BSink(wchar_t * dataArray[]);

static void goodG2B()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Set data to a number less than MAX_LOOP */
    wcscpy(data, L"15");
    dataArray[2] = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_goodB2GSink(wchar_t * dataArray[]);

static void goodB2G()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)//SLIVER_SOURCE
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    dataArray[2] = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_66b_goodB2GSink(dataArray);
}

void CWE606_Unchecked_Loop_Condition__wchar_t_console_66_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_console_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_console_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif


//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:44--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:38 YES
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:44--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:62 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:44--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:84 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:38 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:62 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_66a.c:102--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_66b.c:84 YES
