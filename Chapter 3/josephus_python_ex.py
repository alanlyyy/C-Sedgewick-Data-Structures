def josephus_algo(size, M):

    #populate nums from 1 to size
    item = []
    for num in range(0,size):
        item.append(num+1)

    temp_arr = []

    index = 0
    
    return_val = 0;
    return_index = 0;
    
    #keep track of number of ints left
    nums_left = size
    
    while (nums_left > 1):
    
        if (item[index] != 0):
        
            #append element to temp array
            temp_arr.append(item[index]);
            
            #is len array = M?
            if (len(temp_arr) == M):
                
                #reset the temp arry
                temp_arr = []
                
                print(item[index])
                
                #set current element to 0
                item[index] = 0
                
                nums_left -= 1
        
        
        if (index ==size-1):
            index = 0
        else:
            index +=1
            
        
    for index in range(0,size):
        if (item[index] != 0):
            return_val = item[index]
            return_index = index
            break
    
    return return_index, return_val
    
def josephus_algo_cpp_mirror(size, M):

    #populate nums from 1 to size
    item = [None]*size
    for num in range(0,size):
        item[num] = num + 1
    
    #keeps track of array values that were counted and not deleted
    temp_arr = [None]*M
    
    #keeps track of array indicies that were counted and not deleted
    temp_arr_index = [None]*M
    
    #index used to index into temp_arr elements
    temp_index = 0
    
    #used to track elements in item array
    index = 0
    
    #values that returned when all nums are traversed
    return_val = 0;
    return_index = 0;
    
    #keeps count of number of elements we traversed 
    count = 0
    
    #keep track of number of ints left
    nums_left = size
    
    while (nums_left > 1):
    
        if (item[index] != 0):
            
            #append item[index] that has been seen does not equal to 0
            temp_arr[temp_index] = item[index]
            temp_arr_index[temp_index] = index
            temp_index+=1
            
            #update count, we have seen 1 more non zero value
            count+=1
            
            #is len array = M?
            if (count == M):
                
                #since we know that the last element will be "deleted", the element before the last element would be the element returned.
                return_val = temp_arr[temp_index-2]
                return_index = temp_arr_index[temp_index-2]
                
                #reset the count
                count = 0
                
                #reset temp_arr, after M elements have been seen
                temp_index = 0
                temp_arr = [None] * M
                temp_arr_inde= [None] * M
                
                print(item[index])
                
                #set current element to 0
                item[index] = 0
                
                nums_left -= 1
                
        if (index ==size-1):
            index = 0
        else:
            index +=1
            
    
    return return_index, return_val
    
def josephus_algo_ll_version(size, M):
    #linked list version using arrays for josephus election problem.

    #populate nums from 1 to size
    item = [None]*size
    next = [None]*size
    
    for num in range(0,size):
        item[num] = num + 1
        
        if (num == size-1):
            next[num] = 0
        else:
            next[num] = num+1
    
    #used to track elements in item array
    index = 0
    
    #values that returned when all nums are traversed
    return_val = 0;
    return_index = 0;
    
    #keeps count of number of elements we traversed 
    count = 0
    
    #keep track of number of ints left
    nums_left = size
    
    while (nums_left > 1):
        
        #update count, we have seen 1 more non zero value
        count+=1
            
        #is len array = M?
        if (count == M-1):
            
            #reset the count
            count = 0
            
            next[index] =  next[next[index]]

            print(item[index], " ", next[index])
            
            nums_left -= 1
                
        #move on to the next element
        index = next[index]
        
    return_index = index
    return_val = item[next[index]]
    
    return return_index, return_val


print(josephus_algo(100,9))
#print("----------------")
#print(josephus_algo_cpp_mirror(9,5))
print(josephus_algo_ll_version(100,9))
                
        