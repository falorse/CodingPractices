#!/bin/ruby

require 'json'
require 'stringio'

def anHourglassSum(arr, x, y)
    centerValue = arr[x][y]
    lowersValue = arr[x + 1][y + 1] + arr[x + 1][y] + arr[x + 1][y - 1]
    uppersValue = arr[x - 1][y + 1] + arr[x - 1][y] + arr[x - 1][y - 1]
    return centerValue + lowersValue + uppersValue
end

# Complete the hourglassSum function below.
def hourglassSum(arr)
    eachSum = 0
    maxSum = -255
    for i in 0..15 do
        x = i / 4 + 1
        y = i % 4 + 1
        eachSum = anHourglassSum(arr, x, y)
        if eachSum > maxSum
            maxSum = eachSum
        end
    end
    return maxSum
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

arr = Array.new(6)desc "Task description"
task :task_name => [:dependent, :tasks] do

end

6.times do |i|
    arr[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = hourglassSum arr

fptr.write result
fptr.write "\n"

fptr.close()
