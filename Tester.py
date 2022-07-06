#Author: Israel da Costa Lopes
#Description : This code performs automated software test using random numbers

import subprocess
from random import seed
from random import randint
import random
import string

#Name of the binary application
EXEC_APP_NAME     = "fizzbuzz"
#Maximum number of errors to be dysplayed
VALUE_ERROR_LIMIT = 20
#Number of executions with random number
N_RANDOM_EXEC     = 10
#Number of letter for the string patterns (i.e fizz and buzz)
N_PATTER_LETTER   = 4
#Fault injection for validating the test mechanism
FAULT_INJECTION   = False

#Random number seed
seed(1)

#Reference string list generator to be compared to the execution output
def ref_gen(multiple1, multiple2, limit, pattern1, pattern2):
    str_tmp = ""
    decodedList = []
    for i in range(1, limit + 1):
        str_tmp = ""
        if i%multiple1==0 or i%multiple2==0:
            if i%multiple1==0:
                str_tmp = pattern1
            if i%multiple2==0:
                str_tmp += pattern2
        else:
            str_tmp = str(i)
        decodedList.append(str_tmp)
    return decodedList


#Function to check each value of the execution output and compare with the reference generator
def check_execution(e, expectedStrList, ActualStrList, limit):
    ValueErrorCount = 0
    
    for i in range(limit):
        if expectedStrList[i] != ActualStrList[i]:
            #Report of specific errors for each execution
            if ValueErrorCount < VALUE_ERROR_LIMIT:
                print("ERRROR - Execution ", e, "Expected", expectedStrList[i], "Actual", ActualStrList[i])
            ValueErrorCount +=1
    return ValueErrorCount


#Main function with the software test
if __name__ == '__main__':
    ErrorCount = 0

    #Number number and strings generations
    for i in range(N_RANDOM_EXEC):
        multiple1 = randint(1, 10)
        multiple2 = randint(1, 10)
        limit = randint(1, 100)

        pattern1 = ""
        pattern2 = ""

        #Random generation of which letter of the string patterns 
        for j in range(N_PATTER_LETTER):
           pattern1  += random.choice(string.ascii_letters)
           pattern2  += random.choice(string.ascii_letters)

        #Generation of the reference string list
        expectedStrList = ref_gen(multiple1, multiple2, limit, pattern1, pattern2)

        #Execution of the appication of the nandom parameters as arguments
        appOutput = subprocess.check_output([EXEC_APP_NAME, str(multiple1), str(multiple2), str(limit), pattern1, pattern2])
        ActualStrList = appOutput.decode("utf-8").split(",")

        #Fault injection for validating the test mechanism
        if FAULT_INJECTION:
            ActualStrList.reverse()

        #Sum of the errors of each execution
        if check_execution(i, expectedStrList, ActualStrList, limit) > 0:
            ErrorCount += 1

    #Report of the success for all the executions
    if ErrorCount == 0:
        print("SUCCESS - All the ", N_RANDOM_EXEC, "executions were validated")



    
    

