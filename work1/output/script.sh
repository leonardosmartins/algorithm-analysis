
#!/bin/bash

for i in {1..7}
do
	for j in {1..2}
	do
		for k in  $(seq 0 10 50)
		do
			arquivo="/home/yacov/Documentos/Analise/algorithm-analysis/work1/output/$i-$j-$k.dat"
			echo -e "#\tn\tTempo(ms)" > $arquivo
			for m in {5..15}
			do
				resultado=$(/home/yacov/Documentos/Analise/algorithm-analysis/work1/main $m $j $k $i)
				num=$(echo "2^$m" | bc)
				echo -e "\t$num\t$resultado" >> $arquivo

			done
			sed -i "2s/.*/set output '$i-$j-$k.png'/" plot.gpi
			sed -i "20s/.*/plot '$i-$j-$k.dat' title 'Medicoes' with points, t(x) title 'T(n)' lt 1 lc 3/" plot.gpi
			if [[ ($i == 1 && $j == 2) || ($i == 1 && $k != 0)]]; then 
				sed -i "13s/.*/t(x) = a*x**2 + b*x + c/" plot.gpi
				sed -i "14s/.*/fit t(x) '$i-$j-$k.dat' using 1:2 via a, b, c/" plot.gpi
				sed -i "16s/.*/titulo = sprintf('T(n) = %.4gn**2 + %.4gn + %.4g',a,b,c)/" plot.gpi
				#echo "n ^ 2"
			elif [[ ($i == 1 && $j == 1 && $k == 0) || ($i > 5) ]]; then
				sed -i "13s/.*/t(x) = a*x + b/" plot.gpi
				sed -i "14s/.*/fit t(x) '$i-$j-$k.dat' using 1:2 via a, b/" plot.gpi
				sed -i "16s/.*/titulo = sprintf('T(n) = %.4gn + %.4g',a,b)/" plot.gpi				
				#echo "n"
			else
				#sed -i "13s/.*/t(x) = a*x**2 + b*x + c" plot.gpi
				#sed -i "14s/.*/fit t(x) '$i-$j-$k.dat' using 1:2 via a, b, c" plot.gpi
				#sed -i "16s/.*/titulo = sprintf('T(n) = %.4gn**2 + %.4gn + %.4g',a,b,c)" plot.gpi
				echo "nlog"
			fi

			gnuplot plot.gpi

		done
	done
done


