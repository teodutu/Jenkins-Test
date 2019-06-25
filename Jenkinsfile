pipeline {
    agent any
    stages {
    	stage('checkout') {
    		steps {
  				sh 'git clone https://github.com/teodutu/Jenkins-Test'
    		}
    	}
    	stage('hello') {
    		steps {
    			sh 'echo "Gonna start building..."'
    		}
    	}
    	stage('check compiler') {
    		steps {
    			sh 'gcc --version'
    		}
    	}
        stage('build') {
            steps {
                sh 'make build -C Jenkins-Test && echo "success" || echo "problem"'
            }
        }
        stage('test') {
        	steps {
        		sh 'make run -C Jenkins-Test str1=gigel str2=gigi type=0'
        		sh 'make run -C Jenkins-Test str1=gigel str2=gigi type=1'
        	}
        }
        stage('clean') {
        	steps {
        		sh 'make -C Jenkins-Test clean'
        		sh 'rm -rf Jenkins-Test'
        	}
        }
    }
}

