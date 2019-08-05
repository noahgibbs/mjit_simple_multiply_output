def multiply(a, b, c, d)
  a * b * c * d
end

1_000_000.times do
  multiply(7.0, 10.0, 15.0, 25.0)
end
