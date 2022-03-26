root_path=$(
    cd $(dirname $0)
    pwd
)
echo "root_path: ${root_path}"

mkdir ./build
mkdir ./output

cd build

cmake -G Ninja .. -DCMAKE_CXX_COMPILER_LAUNCHER=ccache
cd ${root_path}/output/
ninja -C ../build
