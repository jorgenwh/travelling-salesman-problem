module Cities

filename = "../european_cities.csv"

function load_cities()::Dict{String, Int}
    open(filename) do f
        while !eof(f)
            line = readline(f)
            data = split(line, ",")
            println(data)
        end
    end
end


end
