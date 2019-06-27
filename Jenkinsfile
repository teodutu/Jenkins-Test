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
        stage('build everything') {
            steps {
                sh 'make build -C Jenkins-Test && echo "success" || echo "problem"'
            }
        }
        stage('test merge_strings') {
        	steps {
                echo "Testing \"merge_strings...\""
        		sh 'make run -C Jenkins-Test arg=merge_strings'
        	}
        }
        stage('test is_palindrome') {
            steps {
                echo "Testing \"is_palindrome...\""
                sh 'make run -C Jenkins-Test arg=is_palindrome'
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