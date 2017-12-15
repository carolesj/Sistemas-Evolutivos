import pandas as pd
from matplotlib import pyplot as plt

def plot(data):

    plt.figure(num=1, figsize=(30, 10), dpi=80, facecolor='w', edgecolor='k')

    plt.subplot(121)
    plt.plot(data[:,1], data[:, 8])
    plt.yscale('linear')
    plt.title('Fitness')

    plt.subplot(122)
    plt.plot(data[:,1], data[:, 3],
             data[:,1], data[:, 4],
             data[:,1], data[:, 5],
             data[:,1], data[:, 6],
             data[:,1], data[:, 7],
    )
    plt.yscale('linear')
    plt.title('Genes')
    plt.legend(('Speed', 'Metabolism', 'Cold Resistance', 'Power', 'Rest Time', 'Thirst'), loc='lower left')
    
    plt.show()


def main():
    
    df = pd.read_csv(filepath_or_buffer='result2.csv', header=None, sep=',')

    df.columns=['epoch', 'generation', 'speed', 'metabolism', 'coldResistance', 'power', 'restTime', 'thirst', 'fitness']
    df.dropna(how="all", inplace=True)

    epoch1 = df.loc[df['epoch'] == 0].values

    epoch2 = df.loc[df['epoch'] == 1].values

    epoch3 = df.loc[df['epoch'] == 2].values

    epoch4 = df.loc[df['epoch'] == 3].values

    plot(epoch1)
    plot(epoch2)
    plot(epoch3)
    plot(epoch4)


if __name__ == '__main__':
    main()