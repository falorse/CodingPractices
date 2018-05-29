#!/bin/ruby

require 'json'
require 'stringio'

def rotate(a, d)
  size = a.size
  rotated_array = [size]
  for i in 0..size - 1
    move_right_space = size - d
    rotated_array[(i + move_right_space) % size] = a[i]
  end

  return rotated_array
end

nd = gets.rstrip.split

n = nd[0].to_i

d = nd[1].to_i

a = gets.rstrip.split(' ').map(&:to_i)

rotated_array = rotate(a, d)

puts rotated_array.join(' ')
