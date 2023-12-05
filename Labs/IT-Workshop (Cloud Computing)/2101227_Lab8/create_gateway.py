import boto3

client = boto3.client('apigateway')


def create_api(name,description,version,types):
    response = client.create_rest_api(
        name=name,
        description=description,
        version=version,
        endpointConfiguration={'types': [types]}
    )
    return response['id']

def create_resource(apiId,parentId,pathPart):
    response=client.create_resource(
        restApiId=apiId,
        parentId=parentId,
        pathPart=pathPart
    )
    return response['id']


def get_parent_id(apiId,parent_resource_path):
    response = client.get_resources(
        restApiId=apiId,
        limit=500  # Adjust the limit as needed to list all resources
    )

    parent_resource_id=''
    # Iterate through the resources to find the parent resource
    for resource in response['items']:
        if resource['path'] == parent_resource_path:
            parent_resource_id = resource['id']
            break
        else:
            # Handle the case where the parent resource is not found
            print(f"Parent resource with path '{parent_resource_path}' not found.")

    return parent_resource_id

def putMethod(apiId,authorizationType,resourceId,httpMethod): 
    client.put_method(
        restApiId=apiId,
        authorizationType=authorizationType,
        resourceId=resourceId,  
        httpMethod=httpMethod,
    )

def putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,url):    
    client.put_integration(
        restApiId=apiId,
        resourceId=resourceId,  
        httpMethod=httpMethod,
        type=type,
        integrationHttpMethod=integrationHttpMethod,
        uri=url
    )

def put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model):
    client.put_method_response(
        restApiId=apiId,
        resourceId=resourceId,
        httpMethod=httpMethod,
        statusCode=statusCode,
        responseModels={
            contentType: Model,
        }
    ) 

def put_integration_response(apiId,resourceId,httpMethod,statusCode):
    client.put_integration_response(
        restApiId=apiId,
        resourceId=resourceId,
        httpMethod=httpMethod,
        statusCode=statusCode,
    )


def create_deployement(apiId,stageName):
    client.create_deployment(
        restApiId=apiId,
        stageName=stageName,
    )
    print("Stage Deployed successfully...")



name='portfolio'
description='Gateway for microservies in portfolio'
version='v-1'
endpointConfigurationType='EDGE'
authorizationType='NONE'
httpMethod='GET'
integrationHttpMethod="GET"
type='HTTP'
statusCode='200'
contentType = 'application/json'
Model='Empty'
stageName='dev'

feedback_url = 'http://ec2-3-6-37-213.ap-south-1.compute.amazonaws.com'
rating_url = 'http://ec2-65-1-131-189.ap-south-1.compute.amazonaws.com'
subscription_url = 'http://ec2-52-66-20-54.ap-south-1.compute.amazonaws.com'

# ***************************************************************
#                     / GET
# ***************************************************************
print("started creating Api Gateway...")

apiId=create_api(name,description,version,endpointConfigurationType)
resourceId=get_parent_id(apiId,'/')
root_resourceId=resourceId
# putMethod(apiId,authorizationType,resourceId,httpMethod)
# putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,feedback_url)
# put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
# put_integration_response(apiId,resourceId,httpMethod,statusCode)
# print("successfully created / GET method...")

# ***************************************************************
#                     /feedback GET
# ***************************************************************

resourceId = create_resource(apiId, root_resourceId, "submissions")
# resourceId=create_resource(apiId,resourceId,"{post+}")
httpMethod='GET'
integrationHttpMethod='GET'
feedback_get_url = feedback_url+'/submissions'
type='HTTP'
putMethod(apiId,authorizationType,resourceId,httpMethod)
putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,feedback_get_url)
put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
put_integration_response(apiId,resourceId,httpMethod,statusCode)
print("successfully created /feedback GET method...")

# ***************************************************************
#                     /feedback POST
# ***************************************************************

# resourceId=create_resource(apiId,root_resourceId,"feedback")
# resourceId=create_resource(apiId,resourceId,"{post+}")
httpMethod='POST'
integrationHttpMethod='POST'
feedback_post_url = feedback_url+'/submit'
type='HTTP'
putMethod(apiId,authorizationType,resourceId,httpMethod)
putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,feedback_post_url)
put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
put_integration_response(apiId,resourceId,httpMethod,statusCode)
print("successfully created /feedback POST method...")

# # ***************************************************************
# #                     / rating GET
# # ***************************************************************


resourceId=create_resource(apiId,root_resourceId,"rating")
httpMethod='GET'
integrationHttpMethod="GET"
type='HTTP'
rating_api_url = rating_url+"/rating"
putMethod(apiId,authorizationType,resourceId,httpMethod)
putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,rating_api_url)
put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
put_integration_response(apiId,resourceId,httpMethod,statusCode)
print("successfully created /rating GET method...")

# # ***************************************************************
# #                     /rating POST
# # ***************************************************************

# feedback_resourceId=resourceId

# resourceId=create_resource(apiId,root_resourceId,"rating")
httpMethod='POST'
integrationHttpMethod="POST"
rating_api_url = rating_url+"/rate"
putMethod(apiId,authorizationType,resourceId,httpMethod)
putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,rating_api_url)
put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
put_integration_response(apiId,resourceId,httpMethod,statusCode)
print("successfully created /feedback/api POST method...")

# # ***************************************************************
# #                     / subscription POST
# # ***************************************************************

resourceId = create_resource(apiId, root_resourceId, "recomsubmit")
httpMethod='POST'
integrationHttpMethod="POST"
type='HTTP'
sub_api_url = subscription_url+"/recomsubmit"
putMethod(apiId,authorizationType,resourceId,httpMethod)
putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,sub_api_url)
put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
put_integration_response(apiId,resourceId,httpMethod,statusCode)
print("successfully created /feedback/post POST method...")

# # ***************************************************************
# #                     / message GET
# # ***************************************************************


httpMethod = 'GET'
integrationHttpMethod = "GET"
type = 'HTTP'
sub_api_url = rating_url+"/recommends"
putMethod(apiId, authorizationType, resourceId, httpMethod)
putIntegration(apiId, httpMethod, resourceId, type,
               integrationHttpMethod, sub_api_url)
put_method_response(apiId, resourceId, httpMethod,
                    statusCode, contentType, Model)
put_integration_response(apiId, resourceId, httpMethod, statusCode)
print("successfully created /rating GET method...")


# resourceId=create_resource(apiId,root_resourceId,"message")
# httpMethod='GET'
# integrationHttpMethod="GET"
# type='HTTP'
# putMethod(apiId,authorizationType,resourceId,httpMethod)
# putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,message_url)
# put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
# put_integration_response(apiId,resourceId,httpMethod,statusCode)
# print("successfully created /message GET method...")

# # ***************************************************************
# #                     / message/api GET
# # ***************************************************************

# message_resourceId=resourceId
# resourceId=create_resource(apiId,message_resourceId,"api")
# httpMethod='GET'
# integrationHttpMethod="GET"
# message_api_url=message_url+'api'
# putMethod(apiId,authorizationType,resourceId,httpMethod)
# putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,message_api_url)
# put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
# put_integration_response(apiId,resourceId,httpMethod,statusCode)
# print("successfully created /messagee/api GET method...")

# # ***************************************************************
# #                     / message/post POST
# # ***************************************************************

# resourceId=create_resource(apiId,message_resourceId,"{post+}")
# httpMethod='POST'
# integrationHttpMethod="POST"
# message_post_url=message_url+'post'
# type='HTTP_PROXY'
# putMethod(apiId,authorizationType,resourceId,httpMethod)
# putIntegration(apiId,httpMethod,resourceId,type,integrationHttpMethod,message_post_url)
# put_method_response(apiId,resourceId,httpMethod,statusCode,contentType,Model)
# put_integration_response(apiId,resourceId,httpMethod,statusCode)
# print("successfully created /message/post POST method...")



create_deployement(apiId,stageName)
print("successfully Deployed API...")
url="https://"+apiId+".execute-api.ap-south-1.amazonaws.com/"+stageName+'/'
print(f"Deployment endpoint for {stageName} : {url}")

