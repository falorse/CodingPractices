#!/bin/ruby

#
# Complete the dynamicArray function below.
#
def dynamicArray(n, queries)
    #
    # Write your code here.
    #

end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')
nq = gets.rstrip.split
n = nq[0].to_i
q = nq[1].to_i

queries = Array.new(q)

q.times do |queries_row_itr|
    queries[queries_row_itr] = gets.rstrip.split(' ').map(&:to_i)
end

result = dynamicArray n, queries

fptr.write result.join "\n"
fptr.write "\n"

fptr.close()
