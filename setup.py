import setuptools as st

ext_modules = [
    st.Extension(
        'embed.example1',
        sources=[
            'embed/example1.cpp',
        ],
    ),
    st.Extension(
        'embed.example2',
        sources=[
            'embed/example2.cpp',
        ],
    ),
    st.Extension(
        'embed.example3',
        sources=[
            'embed/example3.cpp',
        ],
    ),
]

st.setup(
    name='embed',
    packages=st.find_packages(),
    author='Dzhelil Rufat',
    author_email='d@rufat.be',
    ext_modules=ext_modules,
)
