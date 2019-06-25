pipeline {
    agent any
    stages {
    	stage('checkout') {
    		steps {
    			sh 'git clone https://github.com/teodutu/Jenkins-Test.git'
    			sh 'cd Jenkins-Test'
    		}
    	}
    	stage('hello') {
    		steps {
    			echo "Gonna start building..."
    		}
    	}
    	stage('check compiler') {
    		steps {
    			sh 'gcc --version'
    		}
    	}
        stage('build') {
            steps {
                sh 'make build && echo "success" || echo "problem"'
            }
        }
        stage('test') {
        	steps {
        		sh 'make run str1=gigel str2=gigi type=0'
        		sh 'make run str1=gigel str2=gigi type=1'
        	}
        }
    }
}

